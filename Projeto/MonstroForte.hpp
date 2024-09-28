#ifndef MONSTROFORTE_HPP
#define MONSTROFORTE_HPP

#include "Enemy.hpp"

class MonstroForte : public Enemy
{
public:
    MonstroForte(const ObjetoDeJogo &obj) 
        : Enemy(obj, 50, 5) {} 

    
};

#endif // MONSTROFORTE_HPP
