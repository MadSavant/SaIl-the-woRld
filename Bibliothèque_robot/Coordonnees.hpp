/*

Nom			: Coordonnees.h

Description : Fichier contenant la classe Coordonnées

Autheur 	: Gaëtan ROBERT

*/

#ifndef __COORDONNEES_
#define __COORDONNEES_

#define DEPASSEMENT_X	1
#define DEPASSEMENT_Y	2
#define DEPASSEMENT_XY	12
#define DEPASSEMENT_NUL	0

class Coordonnees
{
	private : 
		int16_t			_x;
		int16_t			_y;
		int16_t 		_angle;
		const int16_t 	_maxX 			= 	300;
		const int16_t	_maxY 			= 	800;
		const int16_t	_minAngle		=	0
		const int16_t	_maxAngle 		= 	360;
		
		bool			_depassementX	= false
		bool			_depassementY	= false;
		
		bool 	isEqual(Coordonnees const& b)	const;
	
	public 	:
		//Constructeurs	
		Coordonnees(void);
		Coordonnees(int16_t x, int16_t y);
		Coordonnees(int16_t angle);
		Coordonnees(int16_t x, int16_t y, int16_t angle);
		
		//Opérateur
		bool operator==(Coordonnees const& a, Coordonnees const& b);
		bool operator!=(Coordonnees const& a, Coordonnees const& b);
		Coordonnees& operator+=(Coordonnees const& b);
		Coordonnees& operator-=(Coordonnees const& b);
		Coordonnees operator+(Coordonnees const& a, Coordonnees const& b);
		Coordonnees operator-(Coordonnees const& a, Coordonnees const& b);
		Coordonnees& operator=(Coordonnees const& b);
		
		//get/set
		int16_t getX();
		void setX(int16_t x);
		int16_t getY();
		void setY(int16_t y);
		int16_t getAngle();
		void setAngle(int16_t angle);
		
		//fonctions
		uint8_t depasse(void);
		
};

#endif