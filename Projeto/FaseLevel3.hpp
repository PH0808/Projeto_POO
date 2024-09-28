#ifndef FASELEVEL3_HPP
#define FASELEVEL3_HPP

#include "ASCII_Engine/Fase.hpp"
#include <string>
#include <list>

#include "Enemy.hpp"
#include "Hero.hpp"
#include "ObjetoDeJogo.hpp"

class FaseLevel3 : public Fase
{
public:
    FaseLevel3(std::string name, const Sprite &bkg) : Fase(name, bkg) {}
    FaseLevel3(std::string name, const SpriteAnimado &bkg) : Fase(name, bkg) {}
    virtual ~FaseLevel3() {}

    virtual void init();
    virtual unsigned run(SpriteBuffer &screen);

private:
    Hero *hero;
    ObjetoDeJogo *grub;
    ObjetoDeJogo *chave;

    TextSprite *life;
    std::list<ObjetoDeJogo *> colisoes;
};

#endif // FASELEVEL3_HPP
