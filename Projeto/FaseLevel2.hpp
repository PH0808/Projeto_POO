#ifndef FASELEVEL2_HPP
#define FASELEVEL2_HPP

#include "ASCII_Engine/Fase.hpp"
#include <string>
#include <list>

#include "Enemy.hpp"
#include "Hero.hpp"
#include "MonstroForte.hpp"
#include "ObjetoDeJogo.hpp"

class FaseLevel2 : public Fase
{
public:
    FaseLevel2(std::string name, const Sprite &bkg) : Fase(name, bkg) {}
    FaseLevel2(std::string name, const SpriteAnimado &bkg) : Fase(name, bkg) {}
    virtual ~FaseLevel2() {}

    virtual void init() override;
    virtual unsigned run(SpriteBuffer &screen) override;

    bool colideComBloco() const;

private:
    MonstroForte *monstros[2];
    Hero *hero;
    ObjetoDeJogo *espada;
    ObjetoDeJogo *teletransportadorFase3;
    ObjetoDeJogo *teletransportadorFase1;

    TextSprite *life;

    std::list<ObjetoDeJogo *> colisoes;
};

#endif // FASELEVEL2_HPP
