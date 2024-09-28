#ifndef GAME_HPP
#define GAME_HPP

#include "FaseLevel1.hpp"
#include "FaseLevel2.hpp"
#include "FaseLevel3.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"

class Game
{
public:
	Game(){}
	~Game(){}
	
	static void run()
	{
		SpriteBuffer buffer(250,57);
	
		FaseLevel1 fase1("Fase1",Sprite("rsc/PrimeiraFase.img"));
		FaseLevel2 fase2("Fase2",Sprite("rsc/SegundaFase.img"));
		FaseLevel3 fase3("Fase3",Sprite("rsc/Terceirafase.img"));
		
		// Fase 1
		fase1.init();
		int ret1 = fase1.run(buffer);
		if (ret1 == Fase::GAME_OVER || ret1 == Fase::END_GAME) {
			std::cout << "GAME OVER" << std::endl;
			return;
		}
		
		// Fase 2
		buffer.clear();
		fase2.init();
		int ret2 = fase2.run(buffer);
		if (ret2 == Fase::GAME_OVER || ret2 == Fase::END_GAME) {
			std::cout << "GAME OVER" << std::endl;
			return;
		}
		
		// Fase 3 (Final)
		buffer.clear();
		fase3.init();
		fase3.run(buffer);
		
		std::cout << "Jogo finalizado com sucesso!" << std::endl;
		std::cout << "Saindo..." << std::endl;
	}
};

#endif // GAME_HPP
