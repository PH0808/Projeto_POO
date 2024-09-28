#ifndef FASELEVEL1_HPP
#define FASELEVEL1_HPP

#include "ASCII_Engine/Fase.hpp"
#include <string>
#include <list>

#include "Enemy.hpp"
#include "Hero.hpp"
#include "ObjetoDeJogo.hpp"  

class FaseLevel1 : public Fase
{
public:
    FaseLevel1(std::string name, const Sprite &bkg) : Fase(name, bkg) {}
    FaseLevel1(std::string name, const SpriteAnimado &bkg) : Fase(name, bkg) {}
    virtual ~FaseLevel1() {}

    virtual void init();
    virtual unsigned run(SpriteBuffer &screen);

private:
    Enemy *guardas[2];
    Hero *hero;
    ObjetoDeJogo *teletransportador;  
    TextSprite *life;

    std::list<ObjetoDeJogo *> colisoes;
};

#endif // FASELEVEL1_HPP
