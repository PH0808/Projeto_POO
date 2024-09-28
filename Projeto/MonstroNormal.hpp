#ifndef MONSTRONORMAL_HPP
#define MONSTRONORMAL_HPP

#include "Enemy.hpp"

class MonstroNormal : public Enemy {
public:
    MonstroNormal(const ObjetoDeJogo &obj, int life = 30, int velAtaque = 3) 
        : Enemy(obj, life, velAtaque) {}
    virtual ~MonstroNormal() {}
};

#endif // MONSTRONORMAL_HPP
