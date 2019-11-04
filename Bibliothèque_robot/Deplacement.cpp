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
	
}

//***************************************************
// Constructeur pin only
//***************************************************
Deplacement::Deplacement(const uint16_t pinDirLE, const uint16_t pinStepLE, const uint16_t pinDirRE, const uint16_t pinStepRE)
{
	
}

//***************************************************
// Constructeur Complet
//***************************************************
Deplacement::Deplacement(const uint16_t pinDirLE, const uint16_t pinStepLE, const uint16_t pinDirRE, const uint16_t pinStepRE, const uint16_t speed, const Mode mode)
{
	
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
Deplacement::void setMode(const Mode mode)
{
	
}

Deplacement::Mode getMode()
{
	
}

//***************************************************
// Get - Set pin left engine 
//***************************************************
Deplacement::void setPinLE(const uint16_t pinDir, const uint16_t pinStep)
{
	
}

Deplacement::uint16_t* getPinLE()
{
	
} //penser à l'alloc dynamique

//***************************************************
// Get - Set pin right engine 
//***************************************************
Deplacement::void setPinRE(const uint16_t pinDir, const uint16_t pinStep)
{
	
}

Deplacement::uint16_t* getPinRE()
{
	
} //penser à l'alloc dynamique

//***************************************************
// Get - Set speed
//***************************************************
Deplacement::void setSpeed(const uint8_t speed)
{
	
}

Deplacement::uint8_t getSpeed()
{
	
}

//***************************************************
// Get - Set cote
//***************************************************
Deplacement::void setCote(const uint8_t cote)
{
	
}

Deplacement::uint8_t getCote()
{
	
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
Deplacement::void goStraight(const int8_t sens, const uint16_t distance)
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
Deplacement::void turn(const uint8_t lateralite, const uint16_t angle, const uint16_t radius)
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
Deplacement::void goToStraight(const Coordonnees *coord)
{
	
}

//}

//EOF