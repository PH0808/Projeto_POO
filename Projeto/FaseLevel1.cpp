#include "FaseLevel1.hpp"
#include <iostream>

void FaseLevel1::init()
{
    // Inicializando o teletransportador
    teletransportador = new ObjetoDeJogo("Teletransportador", Sprite("rsc/teleport.img"), 10, 50);  // Coordenadas de exemplo
    objs.push_back(teletransportador);

    // Exemplo de inicialização de outros objetos (guarda, hero, etc)
    guardas[0] = new Enemy(ObjetoDeJogo("Enemy1", SpriteAnimado("rsc/enemy3.anm", 3), 20, 20));
    objs.push_back(guardas[0]);

    hero = new Hero(ObjetoDeJogo("Hero", SpriteAnimado("rsc/hero.anm", 2), 39, 108));
    objs.push_back(hero);

    // Adicionando objetos que fazem colisão
    objs.push_back(new ObjetoDeJogo("Bloco", Sprite("rsc/block.img"), 18, 45));
    colisoes.push_back(objs.back());

    // Outros objetos e colisões...
}

unsigned FaseLevel1::run(SpriteBuffer &screen)
{
    std::string ent;
    draw(screen);
    system("clear");
    show(screen);

    while (true)
    {
        getline(std::cin, ent);

        // Verificando movimentação do herói
        if (ent == "w") hero->moveUp(3);
        else if (ent == "s") hero->moveDown(3);
        else if (ent == "a") hero->moveLeft(3);
        else if (ent == "d") hero->moveRight(3);

        // Verifica se o herói colidiu com o teletransportador
        if (hero->colideCom(*teletransportador))
        {
            return Fase::LEVEL_COMPLETE;  // Exemplo de ação, pode ser ajustado
        }

        // Padrão
        update();
        draw(screen);
        system("clear");
        show(screen);
    }

    return Fase::END_GAME;
}
