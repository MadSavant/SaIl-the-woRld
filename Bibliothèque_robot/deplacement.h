/*

Nom			: deplacement.h

Description : Bibliothèque permettant de gérer les déplacement des robots avec deux stepper

Autheur 	: Gaëtan ROBERT

*/

#ifndef __DEPLACEMENT_
#def __DEPLACEMENT_

/* ================================================================================== *\
   ======================                                      ======================
   ======================             PREPROCESSEUR            ======================
   ======================                                      ======================
\* ================================================================================== */

//{
#include "stm32f3xx_hal.h"

#define SENS_AVANT 		1
#define SENS_ARRIERE	0
#define GAUCHE			2
#define DROITE			3
#define COTE_GAUCHE		11
#define COTE_DROIT		12
//}

/* ================================================================================== *\
   ======================                                      ======================
   ======================              STRUCT/ENUM             ======================
   ======================                                      ======================
\* ================================================================================== */

//{
struct Coord
{
	int16_t x;
	int16_t y;
	int16_t angle;
};

enum Mode
{
	MODE_1_SUR_1,
	MODE_1_SUR_2,
	MODE_1_SUR_4,
	MODE_1_SUR_8,
	MODE_1_SUR_16,
	MODE_1_SUR_32
}	DEPLACEMENT_MODE;

//}

/* ================================================================================== *\
   ======================                                      ======================
   ======================               VARIABLES              ======================
   ======================                                      ======================
\* ================================================================================== */

//{
uint8_t _speed;
uint16_t _pinDirLE;
uint16_t _pinDirRE;
uint16_t _pinStepLE;
uint16_t _pinStepRE;
uint16_t _cote;
Coord _coordActuel;

//}

/* ================================================================================== *\
   ======================                                      ======================
   ======================               FONCTIONS              ======================
   ======================                                      ======================
\* ================================================================================== */

//{
void setMode(const Mode mode);
void setPinLE(const uint16_t pinDir, const uint16_t pinStep);
void setPinRE(const uint16_t pinDir, const uint16_t pinStep);
void setSpeed(const uint8_t speed);
void goStraight(const int8_t sens, const uint16_t distance);
void turn(const uint8_t lateralite, const uint16_t angle, const uint16_t radius);
void goTo(const Coord *coord);
void setCote(const uint8_t cote);

//}

#endif

//EOF