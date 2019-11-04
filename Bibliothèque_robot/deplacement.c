/*

Nom			: deplacement.c

Description : Bibliothèque permettant de gérer les déplacement des robots avec deux stepper

Autheur 	: Gaëtan ROBERT

*/

#include "deplacement.h"

/* ================================================================================== *\
   ======================                                      ======================
   ======================               FONCTIONS              ======================
   ======================                                      ======================
\* ================================================================================== */
//{

//***********************************************************************************
/**
  * @brief change le mode des steppers
  * @param mode (enum Mode)
  * @retval None
  */
void setMode(const Mode mode)
{
	
}

//***********************************************************************************
/**
  * @brief initialise les pin pour le moteur gauche
  * @param pin Direction(uint16_t), pin Step(uint16_t)
  * @retval None
  */
void setPinLE(const uint16_t pinDir, const uint16_t pinStep)
{
	
}

//***********************************************************************************
/**
  * @brief initialise les pin pour le moteur droit
  * @param pin Direction (uint16_t), pin Step (uint16_t)
  * @retval None
  */
void setPinRE(const uint16_t pinDir, const uint16_t pinStep)
{
	
}

//***********************************************************************************
/**
  * @brief modifie la vitesse des moteurs
  * @param speed(uint8_t)
  * @retval None
  */
void setSpeed(const uint8_t speed)
{
	
}

//***********************************************************************************
/**
  * @brief fait avancer le robot en ligne droite
  * @param sens (int8_t / CONST), distance (uint16_t)
  * @retval None
  */
void goStraight(const int8_t sens, const uint16_t distance)
{
	
}

//***********************************************************************************
/**
  * @brief effectue un virage (peut être sur place)
  * @param lateralite(uint16_t), angle(uint16_t), radius(uint16_t)
  * @retval None
  */
void turn(const uint8_t lateralite, const uint16_t angle, const uint16_t radius)
{
	
}

//***********************************************************************************
/**
  * @brief envoie le robot aux coordonnées indiquées
  * @param *coord (ptr_Coord)
  * @retval None
  */
void goTo(const Coord *coord)
{
	
}

//***********************************************************************************
/**
  * @brief indique le coté du terrain où le robot est
  * @param cote (uint8_t / CONST)
  * @retval None
  */
void setCote(const uint8_t cote)
{
	
}

//}

//OEF