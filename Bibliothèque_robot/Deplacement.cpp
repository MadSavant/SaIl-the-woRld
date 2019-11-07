#include "Deplacement.hpp"

//using namespace robotDepl;

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
Deplacement::Deplacement(const uint16_t pinDirLE, const uint16_t pinStepLE, const uint16_t pinDirRE, const uint16_t pinStepRE, const uint16_t speed, const uint8_t mode)
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
void Deplacement::setMode(const uint8_t mode)
{
	_mode = mode;
	
	switch(_mode)
	{
		case MODE_1_SUR_1:
			_m0 = GPIO_PIN_RESET;
			_m1 = GPIO_PIN_RESET;
			_m2 = GPIO_PIN_RESET;
			break;
			
		case MODE_1_SUR_2:
			_m0 = GPIO_PIN_RESET;
			_m1 = GPIO_PIN_RESET;
			_m2 = GPIO_PIN_SET;
			break;
			
		case MODE_1_SUR_4:
			_m0 = GPIO_PIN_RESET;
			_m1 = GPIO_PIN_SET;
			_m2 = GPIO_PIN_RESET;
			break;
			
		case MODE_1_SUR_8:
			_m0 = GPIO_PIN_RESET;
			_m1 = GPIO_PIN_SET;
			_m2 = GPIO_PIN_SET;
			break;
			
		case MODE_1_SUR_16:
			_m0 = GPIO_PIN_SET;
			_m1 = GPIO_PIN_RESET;
			_m2 = GPIO_PIN_RESET;
			break;
			
		case MODE_1_SUR_32:
			_m0 = GPIO_PIN_SET;
			_m1 = GPIO_PIN_SET;
			_m2 = GPIO_PIN_SET;
			break;
			
		default :
			_m0 = GPIO_PIN_RESET;
			_m1 = GPIO_PIN_RESET;
			_m2 = GPIO_PIN_RESET;
	}
	
	
}

uint8_t Deplacement::getMode()
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
	static uint16_t ret[2];
	
	//ret = (uint16_t*)malloc(sizeOf(uint16_t)*2);
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
	static uint16_t ret[2];
	
	//ret = (uint16_t*)malloc(sizeOf(uint16_t)*2);
	ret[0] = _pinDirRE;
	ret[1] = _pinStepRE;
	
	return ret;
} //penser à l'alloc dynamique

//***************************************************
// Get - Set speed
//***************************************************
void Deplacement::setSpeed(const uint16_t speed)
{
	_speed = speed;
}

uint16_t Deplacement::getSpeed()
{
	return _speed;
}

//***************************************************
// Get - Set cote
//***************************************************
void Deplacement::setCote(const uint16_t cote)
{
	if(cote == COTE_GAUCHE || cote == COTE_DROIT)
		_cote = cote;
}

uint16_t Deplacement::getCote()
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

//***************************************************
// Get - Set coordActuel
//***************************************************
void Deplacement::setAccel(const uint16_t accel)
{
	_accel = accel;
}

uint16_t Deplacement::getAccel()
{
	return _accel;
}

//***************************************************
// Get - Set coordActuel
//***************************************************
void Deplacement::setRayonRoue(const uint16_t rayon)
{
	_rayonRoue = rayon;
}

uint16_t Deplacement::getRayonRoue()
{
	return _rayonRoue;
}

//***************************************************
// Get - Set pin Mode
//***************************************************
void Deplacement::setPinM0(const uint16_t pin)
{
	_pinMode0 = pin;
}

uint16_t Deplacement::getPinM0()
{
	return _pinMode0;
}

void Deplacement::setPinM1(const uint16_t pin)
{
	_pinMode1 = pin;
}

uint16_t Deplacement::getPinM1()
{
	return _pinMode1;
}

void Deplacement::setPinM2(const uint16_t pin)
{
	_pinMode2 = pin;
}

uint16_t Deplacement::getPinM2()
{
	return _pinMode2;
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
// out :			uint16_t	DEPASSEMENT_STATE
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
// out :			uint16_t	DEPASSEMENT_STATE
//
//***************************************************
void Deplacement::turn(const uint16_t lateralite, const uint16_t angle, const uint16_t radius)
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
// Fonction : 		goTo
//
// Description : 	envoie le robot aux coordonnées 
//					en ligne droite
//
// in :				Coordonnees coord
// out :			void
//
//***************************************************
void Deplacement::goTo(const Coordonnees *coord)
{
	
}

//}

/* ================================================================================== *\		//En construction
   ======================                                      ======================
   ======================          FONCTIONS CALCULS           ======================
   ======================                                      ======================
\* ================================================================================== */

//{
//***************************************************
//
// Fonction : 		curveAccel
//
// Description : 	calcul la vitesse instantannée 
//
// in :				uint16_t distance
// out :			void
//
//***************************************************
void Deplacement::curveAccel(const uint16_t distance)
{
	if(_speed * _speed > _accel * distance)	//cas où le robot n'a pas le temps d'atteindre la vitesse max
	{
		float tm = sqrt(distance / _accel); //Temps milieu
		if(tm){}//avoid warning
	}
	
	else
	{
		float tm = _speed/_accel;	//temps montée et descente
		float tc = distance / _speed - _speed / _accel; //temps vitesse constante
		if(tm && tc){}//avoid warning
	}
}

//***************************************************
//
// Fonction : 		onePulse
//
// Description : 	calcul la vitesse instantannée 
//
// in :				uint16_t vitesseInstant
// out :			void
//
//***************************************************
void Deplacement::onePulse(const uint16_t vitesseInstant)
{
	
}

//}

//EOF