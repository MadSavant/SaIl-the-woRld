/*

Nom			: Coordonnees.h

Description : Classe qui les gère déplacement des robots

Autheur 	: Gaëtan ROBERT

*/

#ifndef __DEPLACEMENT_
#define __DEPLACEMENT_

//#include "Deplacement.cpp"

#include "Coordonnees.hpp"
#include "stm32f3xx_hal.h"

#define COTE_DROIT	0
#define COTE_GAUCHE	1

#define PI 3.14159265359

#define	MODE_1_SUR_1	1
#define	MODE_1_SUR_2	2
#define	MODE_1_SUR_4	4
#define	MODE_1_SUR_8	8
#define	MODE_1_SUR_16	16
#define	MODE_1_SUR_32	32

// namespace robotDepl
// {
	class Deplacement
	{
		private :
			uint16_t		_speed;
			Coordonnees 	_coordActuel;
			uint8_t			_mode = MODE_1_SUR_1;
			uint16_t 		_pinDirLE;
			uint16_t 		_pinDirRE;
			uint16_t 		_pinStepLE;
			uint16_t 		_pinStepRE;
			uint16_t 		_pinMode0;
			uint16_t 		_pinMode1;
			uint16_t 		_pinMode2;
			uint16_t		_m0;
			uint16_t		_m1;
			uint16_t		_m2;		
			uint16_t 		_cote = COTE_GAUCHE;
			uint16_t		_accel = 1000;//mm/s-2
			uint16_t		_rayonRoue = 50;
			
			
		public :
			//Constructeurs
			Deplacement();
			Deplacement(const uint16_t pinDirLE, const uint16_t pinStepLE, const uint16_t pinDirRE, const uint16_t pinStepRE);
			Deplacement(const uint16_t pinDirLE, const uint16_t pinStepLE, const uint16_t pinDirRE, const uint16_t pinStepRE, const uint16_t speed, const uint8_t mode);
			
			//Get - Set
			void setMode(const uint8_t mode);
			uint8_t getMode();
			void setPinLE(const uint16_t pinDir, const uint16_t pinStep);
			uint16_t* getPinLE(); //penser à l'alloc dynamique
			void setPinRE(const uint16_t pinDir, const uint16_t pinStep);
			uint16_t* getPinRE(); //penser à l'alloc dynamique
			void setSpeed(const uint16_t speed);
			uint16_t getSpeed();
			void setCote(const uint16_t cote);
			uint16_t getCote();
			void setCoordonneesActuelles(const Coordonnees coord);
			Coordonnees getCoordonneesActuelles();
			void setAccel(const uint16_t accel);
			uint16_t getAccel();
			void setRayonRoue(const uint16_t rayon);
			uint16_t getRayonRoue();
			void setPinM0(const uint16_t pin);
			uint16_t getPinM0();
			void setPinM1(const uint16_t pin);
			uint16_t getPinM1();
			void setPinM2(const uint16_t pin);
			uint16_t getPinM2();
			
			
			//Fonctions de base
			void goStraight(const int8_t sens, const uint16_t distance);
			void turn(const uint16_t lateralite, const uint16_t angle, const uint16_t radius);
			
			//Fonctions avancées
			void goTo(const Coordonnees *coord);
			
			//Fonctions calculs
			void curveAccel(const uint16_t distance);
			void onePulse(const uint16_t vitesseInstant);
	};
// }

#include "Deplacement.cpp"

#endif