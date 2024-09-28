#include "FaseLevel2.hpp"
#include <iostream>

void FaseLevel2::init()
{
    // Hero
    hero = new Hero(ObjetoDeJogo("Hero", SpriteAnimado("rsc/hero.anm", 2), 39, 108));
    objs.push_back(hero);

    // Monstros fortes
    monstros[0] = new MonstroForte(ObjetoDeJogo("MonstroForte1", SpriteAnimado("rsc/monstroForte.anm", 3), 20, 20));
    objs.push_back(monstros[0]);

    monstros[1] = new MonstroForte(ObjetoDeJogo("MonstroForte2", SpriteAnimado("rsc/monstroForte.anm", 3), 35, 180));
    objs.push_back(monstros[1]);

    // Espada
    espada = new ObjetoDeJogo("Espada", Sprite("rsc/espada.img"), 12, 140);
    objs.push_back(espada);

    // Teletransportador para Fase 3
    teletransportadorFase3 = new ObjetoDeJogo("TeleFase3", Sprite("rsc/teleport.img"), 50, 100);
    objs.push_back(teletransportadorFase3);

    // Teletransportador para Fase 1
    teletransportadorFase1 = new ObjetoDeJogo("TeleFase1", Sprite("rsc/teleport.img"), 10, 100);
    objs.push_back(teletransportadorFase1);

    // Life
    objs.push_back(new ObjetoDeJogo("Life", TextSprite("####################"), 7, 85));
    SpriteBase *tmp = const_cast<SpriteBase *>(objs.back()->getSprite());
    life = dynamic_cast<TextSprite *>(tmp);

    // Blocos
    objs.push_back(new ObjetoDeJogo("B1", Sprite("rsc/castlelateral.img"), 80, 38));
    colisoes.push_back(objs.back());

    objs.push_back(new ObjetoDeJogo("B2", Sprite("rsc/castleinferior.img"), 50, 38));
    colisoes.push_back(objs.back());

    objs.push_back(new ObjetoDeJogo("B3", Sprite("rsc/blocklateral.img"), 18, 132));
    colisoes.push_back(objs.back());

    objs.push_back(new ObjetoDeJogo("B4", Sprite("rsc/blocosuperior.img"), 33, 45));
    colisoes.push_back(objs.back());
}

unsigned FaseLevel2::run(SpriteBuffer &screen)
{
    std::string ent;

    // Desenha o cenário inicial
    draw(screen);
    system("clear");
    show(screen);

    while (true)
    {
        // Leitura da entrada
        getline(std::cin, ent);

        // Processando entradas de movimento do Hero
        int posL = hero->getPosL(), posC = hero->getPosC();

        if (ent == "w" && hero->getPosL() > 10)
            hero->moveUp(3);
        else if (ent == "s" && hero->getPosL() < screen.getAltura() - 15)
            hero->moveDown(3);
        else if (ent == "a" && hero->getPosC() > 12)
            hero->moveLeft(3);
        else if (ent == "d" && hero->getPosC() < screen.getLargura() - hero->getSprite()->getLargura() - 13)
            hero->moveRight(3);
        else if (ent == "x")
        {
            for (int g = 0; g < 2; g++)
            {
                if (hero->colideCom(*monstros[g]))
                {
                    monstros[g]->sofrerAtaque(hero->atacar());
                    if (!monstros[g]->isAlive())
                    {
                        monstros[g]->desativarObj();
                        // Verifica se o MonstroForte foi derrotado e teletransporta o Hero
                        if (g == 1) 
                            return Fase::TELEPORT_TO_LEVEL3; // Teletransporta para a terceira fase
                    }
                }
            }
        }
        else if (ent == "q")
            return Fase::END_GAME;

        // Lógica de colisão
        if (colideComBloco())
            hero->moveTo(posL, posC);

        // Processando eventos de ataque
        for (int g = 0; g < 2; g++)
        {
            if (hero->colideCom(*monstros[g]))
            {
                hero->sofrerAtaque(monstros[g]->atacar());

                if (!hero->isAlive())
                    return Fase::GAME_OVER;

                life->setText(std::string(hero->getLife() / 5, '#'));
            }
        }

        // Verifica se o Hero colidiu com a espada
        if (hero->colideCom(*espada))
        {
            espada->desativarObj();
            hero->fortalecer(); // Presumindo que o método fortalecer() existe no Hero
        }

        // Atualiza e exibe o estado da fase
        update();
        draw(screen);
        system("clear");
        show(screen);
    }

    return Fase::END_GAME; // Caso saia do loop
}

bool FaseLevel2::colideComBloco() const
{
    for (auto it = colisoes.begin(); it != colisoes.end(); ++it)
    {
        if (hero->colideCom(**it))
        {
            return true;
        }
    }

    return false;
}
