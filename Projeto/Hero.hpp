#ifndef HERO_HPP
#define HERO_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Hero : public ObjetoDeJogo
{
public:
    Hero(const ObjetoDeJogo &obj, int life = 100) 
        : ObjetoDeJogo(obj), life(life), grubSalvo(false) {}
    virtual ~Hero() {}

    bool isAlive() const { return life > 0; }
    int getLife() const { return life; }

    void sofrerAtaque(int ataque) { 
        life = (life - ataque >= 0) ? (life - ataque) : 0; 
    }
    int atacar() const { return 10; }

    void salvarGrub() { grubSalvo = true; } // Método para salvar Grub
    bool salvouGrub() const { return grubSalvo; } // Verifica se o Grub foi salvo

    void pegarChave() { temChave = true; } // Adicionando a lógica para pegar a chave
    bool possuiChave() const { return temChave; } // Verifica se o herói tem a chave

    void fortalecer() { // Método para fortalecer o herói
        life += 20;  // Aumenta a vida do herói
        attackPower += 5;  // Aumenta o poder de ataque
    }

private:
    int life;
    int attackPower = 10; // Poder de ataque padrão
    bool grubSalvo; // Indica que o Grub foi salvo
    bool temChave = false; // Indica se o herói possui a chave
};

#endif // HERO_HPP
