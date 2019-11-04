#include "Coordonnes.hpp"


/* ================================================================================== *\
   ======================                                      ======================
   ======================             CONSTRUCTEURS            ======================
   ======================                                      ======================
\* ================================================================================== */

//{
//***************************************************
// Constructeur vide
//***************************************************
Coordonnees::Coordonnees()
{
	_x  	=	0;
	_y		=	0;
	
	_angle	=	0;
}

//***************************************************
// Constructeur avec x et y
//***************************************************
Coordonnees::Coordonnees(int16_t x, int16_t y)
{
	//coordonnées entre -max et max
	_x  	=	(abs(x) > _maxX)	?	_maxX * x/abs(x)	:	x;
	_y		=	(abs(y) > _maxY)	?	_maxY * y/abs(y)	:	y;
	
	_angle	=	0;
}

//***************************************************
// Constructeur avec l'angle
//***************************************************
Coordonnees::Coordonnees(int16_t angle)
{
	_x  	=	0;
	_y		=	0;
	
	_angle	=	angle;
	
	//Angle entre minAngle et maxAngle
	while(_angle < _minAngle)	
	{
		_angle += 360;
	}
	while(_angle > _maxAngle)
	{
		_angle -= 360;
	}
}

//***************************************************
// Constructeur avec x, y et l'angle
//***************************************************
Coordonnees::Coordonnees(int16_t x, int16_t y, int16_t angle)
{
	//coordonnées entre -max et max
	_x  	=	(abs(x) > _maxX)	?	_maxX * x/abs(x)	:	x;
	_y		=	(abs(y) > _maxY)	?	_maxY * y/abs(y)	:	y;
	
	_angle	=	angle;
	
	//Angle entre minAngle et maxAngle
	while(_angle < _minAngle)	
	{
		_angle += 360;
	}
	while(_angle > _maxAngle)
	{
		_angle -= 360;
	}
}
//}

/* ================================================================================== *\
   ======================                                      ======================
   ======================          FONCTIONS INTERNES          ======================
   ======================                                      ======================
\* ================================================================================== */

//{
bool Coordonnees::isEqual(Coordonnees const& b) const
{
	return (_x == b._x && _y == b._y && _angle == b._angle);
}
//}

/* ================================================================================== *\
   ======================                                      ======================
   ======================              OPERATEURS              ======================
   ======================                                      ======================
\* ================================================================================== */

//{
//***************************************************
// Opérateur ==
//***************************************************
bool Coordonnees::operator==(Coordonnees const& a, Coordonnees const& b)
{
	return a.isEqual(b);
}

//***************************************************
// Opérateur !=
//***************************************************
bool Coordonnees::operator!=(Coordonnees const& a, Coordonnees const& b)
{
    return !(a==b); 
}

//***************************************************
// Opérateur +=
//***************************************************
Coordonnees& Coordonnees::operator+=(Coordonnees const& b)
{
	_x += b._x;
	if(abs(_x) >_maxX) //gère le dépassement
	{
		_x = _maxX * _x/abs(_x);
		_depassementX = true;
	}		
	
	_y += b._y;
	if(abs(_y) >_maxY) //gère le dépassement
	{
		_y = _maxY * _y/abs(_y);
		_depassementY = true;
	}
	
	_angle += b._angle;
	
	//Angle entre minAngle et maxAngle
	while(_angle < _minAngle)	
	{
		_angle += 360;
	}
	while(_angle > _maxAngle)
	{
		_angle -= 360;
	}
	
	return *this;
}

//***************************************************
// Opérateur -=
//***************************************************
Coordonnees& Coordonnees::operator-=(Coordonnees const& b)
{
	_x -= b._x;
	if(abs(_x) >_maxX)
	{
		_x = _maxX * _x/abs(_x);
		_depassementX = true;
	}		
	
	_y -= b._y;
	if(abs(_y) >_maxY)
	{
		_y = _maxY * _y/abs(_y);
		_depassementY = true;
	}
	
	_angle -= b._angle;
	
	//Angle entre minAngle et maxAngle
	while(_angle < _minAngle)	
	{
		_angle += 360;
	}
	while(_angle > _maxAngle)
	{
		_angle -= 360;
	}
	
	return *this;
}

//***************************************************
// Opérateur +
//***************************************************
Coordonnees Coordonnees::operator+(Coordonnees const& a, Coordonnees const& b)
{
	Coordonnees result(a);
	result += b;
	return result;
}

//***************************************************
// Opérateur -
//***************************************************
Coordonnees Coordonnees::operator-(Coordonnees const& a, Coordonnees const& b)
{
	Coordonnees result(a);
	result -= b;
	return result;
}

//***************************************************
// Opérateur =
//***************************************************
Coordonnees& operator=(Coordonnees const& b)
{
	if(this != &b)
		return *this;
}

//}

/* ================================================================================== *\
   ======================                                      ======================
   ======================              GET / SET               ======================
   ======================                                      ======================
\* ================================================================================== */

//{
//***************************************************
// Get - Set x
//***************************************************
int16_t Coordonnees::getX()
{
	return _x;
}

void Coordonnees::setX(int16_t x)
{
	_x = x;
	if(abs(_x) >_maxX)
	{
		_x = _maxX * _x/abs(_x);
		_depassementX = true;
	}		
}

//***************************************************
// Get - Set y
//***************************************************

int16_t Coordonnees::getY()
{
	return _y;
}

void Coordonnees::setY(int16_t y)
{
	_y = y;
	if(abs(_y) >_maxY)
	{
		_y = _maxY * _y/abs(_y);
		_depassementY = true;
	}
}

//***************************************************
// Get - Set angle
//***************************************************

int16_t Coordonnees::getAngle()
{
	return _angle;
}

void Coordonnees::setAngle(int16_t angle)
{
	_angle = angle;
	
	//Angle entre minAngle et maxAngle
	while(_angle < _minAngle)	
	{
		_angle += 360;
	}
	while(_angle > _maxAngle)
	{
		_angle -= 360;
	}
}
//}

/* ================================================================================== *\
   ======================                                      ======================
   ======================              FONCTIONS               ======================
   ======================                                      ======================
\* ================================================================================== */

//{
//***************************************************
//
// Fonction : 		depasse
//
// Description : 	indique s'il y a eu un 
//					dépassement
//
// in :				void
// out :			uint8_t	DEPASSEMENT_STATE
//
//***************************************************
uint8_t Coordonnees::depasse(void);
{
	if(_depassementX && _depassementY) 	return DEPASSEMENT_XY;
	else if(_depassementX)				return DEPASSEMENT_X;
	else if(_depassementY)				return DEPASSEMENT_Y;
	else 								return DEPASSEMENT_NUL;
}
//}
//EOF