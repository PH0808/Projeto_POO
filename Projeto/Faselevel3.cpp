#include "FaseLevel3.hpp"
#include <iostream>

void FaseLevel3::init()
{
    // Inicializando objetos de jogo
    grub = new ObjetoDeJogo("Grub", SpriteAnimado("rsc/grub.anm", 2), 16, 196); // Grub preso no chão
    objs.push_back(grub);

    chave = new ObjetoDeJogo("Chave", Sprite("rsc/key.img"), 12, 140); // Chave na fase
    objs.push_back(chave);

    hero = new Hero(ObjetoDeJogo("Hero", SpriteAnimado("rsc/hero.anm", 2), 39, 108));
    objs.push_back(hero);

    // Inicializa a vida do herói
    objs.push_back(new ObjetoDeJogo("Life", TextSprite("####################"), 7, 85));
    SpriteBase *tmp = const_cast<SpriteBase *>(objs.back()->getSprite());
    life = dynamic_cast<TextSprite *>(tmp);

    // Blocos ou colisões
    objs.push_back(new ObjetoDeJogo("B1", Sprite("rsc/level3Block1.img"), 18, 38));
    colisoes.push_back(objs.back());

    objs.push_back(new ObjetoDeJogo("B2", Sprite("rsc/level3Block2.img"), 33, 38));
    colisoes.push_back(objs.back());

    objs.push_back(new ObjetoDeJogo("B3", Sprite("rsc/level3Block3.img"), 33, 132));
    colisoes.push_back(objs.back());
}

unsigned FaseLevel3::run(SpriteBuffer &screen)
{
    std::string ent;

    // Desenho padrão
    draw(screen);
    system("clear");
    show(screen);

    while (true)
    {
        // Lendo entrada
        getline(std::cin, ent);

        // Processando entradas
        int posL = hero->getPosL(), posC = hero->getPosC();

        // Movimentação do herói
        if (ent == "w" && hero->getPosL() > 10)
            hero->moveUp(3);
        else if (ent == "s" && hero->getPosL() < screen.getAltura() - 15)
            hero->moveDown(3);
        else if (ent == "a" && hero->getPosC() > 12)
            hero->moveLeft(3);
        else if (ent == "d" && hero->getPosC() < screen.getLargura() - hero->getSprite()->getLargura() - 13)
            hero->moveRight(3);
        else if (ent == "x") {
            // Ataque (não há inimigos nesta fase)
        }
        else if (ent == "q")
            return Fase::END_GAME;

        // Checagem de colisões
        if (hero->colideCom(*chave))
        {
            chave->desativarObj();
            hero->pegarChave(); // Hero pega a chave
        }
        else if (hero->colideCom(*grub))
        {
            grub->desativarObj(); // Resgatar o Grub
            return Fase::END_GAME; // Finaliza o jogo
        }

        // Checa colisões com blocos
        if (colideComBloco())
            hero->moveTo(posL, posC); // Retorna à posição anterior se colidir com um bloco

        // Atualiza e desenha
        update();
        draw(screen);
        system("clear");
        show(screen);
    }

    return Fase::END_GAME; // Não necessário, mas mantém a lógica
}

bool FaseLevel3::colideComBloco() const
{
    for (auto it = colisoes.begin(); it != colisoes.end(); ++it)
    {
        if (hero->colideCom(**it))
            return true;
    }
    return false;
}
