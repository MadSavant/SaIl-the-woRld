#include "Deplacement.hpp"

/* ================================================================================== *\
   ======================                                      ======================
   ======================             CONSTRUCTEURS            ======================
   ======================                                      ======================
\* ================================================================================== */

//{
//***************************************************
// Constructeur vide
//***************************************************
Deplacement::Deplacement()
{
	_speed 			=	128;
	_pinDirLE		=	4;
	_pinDirRE		=	5;
	_pinStepLE		=	6;
	_pinStepRE		=	7;
}

//***************************************************
// Constructeur pin only
//***************************************************
Deplacement::Deplacement(const uint16_t pinDirLE, const uint16_t pinStepLE, const uint16_t pinDirRE, const uint16_t pinStepRE)
{
	_speed 			=	128;
	_pinDirLE		=	pinDirLE;
	_pinDirRE		=	pinDirRE;
	_pinStepLE		=	pinStepLE;
	_pinStepRE		=	pinStepRE;
}

//***************************************************
// Constructeur Complet
//***************************************************
Deplacement::Deplacement(const uint16_t pinDirLE, const uint16_t pinStepLE, const uint16_t pinDirRE, const uint16_t pinStepRE, const uint16_t speed, const Mode mode)
{
	_speed 			=	speed;
	_mode			=	mode;
	_pinDirLE		=	pinDirLE;
	_pinDirRE		=	pinDirRE;
	_pinStepLE		=	pinStepLE;
	_pinStepRE		=	pinStepRE;
}
//}

/* ================================================================================== *\
   ======================                                      ======================
   ======================              GET / SET               ======================
   ======================                                      ======================
\* ================================================================================== */

//{
//***************************************************
// Get - Set Mode
//***************************************************
void Deplacement::setMode(const Mode mode)
{
	_mode = mode;
}

Mode Deplacement::getMode()
{
	return _mode;
}

//***************************************************
// Get - Set pin left engine (DIR - STEP)
//***************************************************
void Deplacement::setPinLE(const uint16_t pinDir, const uint16_t pinStep)
{
	_pinDirLE 	= pinDir;
	_pinStepLE 	= pinStep;
}

uint16_t* Deplacement::getPinLE()
{
	uint16_t ret[2];
	
	ret = (uint16_t*)malloc(sizeOf(uint16_t)*2);
	ret[0] = _pinDirLE;
	ret[1] = _pinStepLE;
	
	return ret;
} //penser à l'alloc dynamique

//***************************************************
// Get - Set pin right engine (DIR - STEP)
//***************************************************
void Deplacement::setPinRE(const uint16_t pinDir, const uint16_t pinStep)
{
	_pinDirRE 	= pinDir;
	_pinStepRE 	= pinStep;
}

uint16_t* Deplacement::getPinRE()
{
	uint16_t ret[2];
	
	ret = (uint16_t*)malloc(sizeOf(uint16_t)*2);
	ret[0] = _pinDirRE;
	ret[1] = _pinStepRE;
	
	return ret;
} //penser à l'alloc dynamique

//***************************************************
// Get - Set speed
//***************************************************
void Deplacement::setSpeed(const uint8_t speed)
{
	_speed = speed;
}

uint8_t Deplacement::getSpeed()
{
	return speed;
}

//***************************************************
// Get - Set cote
//***************************************************
void Deplacement::setCote(const uint8_t cote)
{
	if(cote == COTE_GAUCHE || cote == COTE_DROIT)
		_cote = cote;
}

uint8_t Deplacement::getCote()
{
	return _cote;
}

//***************************************************
// Get - Set coordActuel
//***************************************************
void Deplacement::setCoordonneesActuelles(const Coordonnees coord)
{
	_coordActuel = coord;
}

Coordonnees Deplacement::getCoordonneesActuelles()
{
	return _coordActuel;
}
//}

/* ================================================================================== *\
   ======================                                      ======================
   ======================          FONCTIONS DE BASE           ======================
   ======================                                      ======================
\* ================================================================================== */

//{
//***************************************************
//
// Fonction : 		goStraight
//
// Description : 	indique s'il y a eu un 
//					dépassement
//
// in :				void
// out :			uint8_t	DEPASSEMENT_STATE
//
//***************************************************
void Deplacement::goStraight(const int8_t sens, const uint16_t distance)
{
	
}

//***************************************************
//
// Fonction : 		turn
//
// Description : 	effectue un virage
//
// in :				void
// out :			uint8_t	DEPASSEMENT_STATE
//
//***************************************************
void Deplacement::turn(const uint8_t lateralite, const uint16_t angle, const uint16_t radius)
{
	
}
//}

/* ================================================================================== *\
   ======================                                      ======================
   ======================          FONCTIONS AVANCEES          ======================
   ======================                                      ======================
\* ================================================================================== */

//{
//***************************************************
//
// Fonction : 		goToStraight
//
// Description : 	envoie le robot aux coordonnées 
//					en ligne droite
//
// in :				Coordonnees coord
// out :			void
//
//***************************************************
void Deplacement::goToStraight(const Coordonnees *coord)
{
	
}

//}

//EOF