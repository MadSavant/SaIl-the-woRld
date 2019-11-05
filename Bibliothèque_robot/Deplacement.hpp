/*

Nom			: Coordonnees.h

Description : Classe qui les gère déplacement des robots

Autheur 	: Gaëtan ROBERT

*/

#ifndef __DEPLACEMENT_
#define __DEPLACEMENT_

#include "Coordonnees.hpp"

#define COTE_DROIT	0
#define COTE_GAUCHE	1

enum Mode
{
	MODE_1_SUR_1,
	MODE_1_SUR_2,
	MODE_1_SUR_4,
	MODE_1_SUR_8,
	MODE_1_SUR_16,
	MODE_1_SUR_32
};

class Deplacement
{
	private :
		uint8_t			_speed;
		Coordonnees 	_coordActuel;
		Mode			_mode = MODE_1_SUR_1;
		uint16_t 		_pinDirLE;
		uint16_t 		_pinDirRE;
		uint16_t 		_pinStepLE;
		uint16_t 		_pinStepRE;
		uint16_t 		_cote = COTE_GAUCHE;
		
	public :
		//Constructeurs
		Deplacement();
		Deplacement(const uint16_t pinDirLE, const uint16_t pinStepLE, const uint16_t pinDirRE, const uint16_t pinStepRE);
		Deplacement(const uint16_t pinDirLE, const uint16_t pinStepLE, const uint16_t pinDirRE, const uint16_t pinStepRE, const uint16_t speed, const Mode mode);
		
		//Get - Set
		void setMode(const Mode mode);
		Mode getMode();
		void setPinLE(const uint16_t pinDir, const uint16_t pinStep);
		uint16_t* getPinLE(); //penser à l'alloc dynamique
		void setPinRE(const uint16_t pinDir, const uint16_t pinStep);
		uint16_t* getPinRE(); //penser à l'alloc dynamique
		void setSpeed(const uint8_t speed);
		uint8_t getSpeed();
		void setCote(const uint8_t cote);
		uint8_t getCote();
		void setCoordonneesActuelles(const Coordonnees coord);
		Coordonnees getCoordonneesActuelles();
		
		//Fonctions de base
		void goStraight(const int8_t sens, const uint16_t distance);
		void turn(const uint8_t lateralite, const uint16_t angle, const uint16_t radius);
		
		//Fonctions avancées
		void goTo(const Coord *coord);
};

#endif