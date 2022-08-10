#include "Ghost_types.h"
//////////////////
Blinky::Blinky(Position p)
{
	{
		this->pos.x = p.x;
		this->pos.y = p.y;
		horg = 13;
		verg = 12;
		mapPos.x = 310;
		mapPos.y = 65;
		scatter = false;
		color = 'r'; //red.
	}
}
void Blinky::initVariables()
{
	horg = 13;
	verg = 12;
}
void Blinky::scatter_mode()
{
	if (scatter && (verg <= 1 && horg>= 1))
	{
		cout << "blinky-Scattering.";
		Position s;
		s.x = 1;
		s.y = 1;
		Target(s);
	}
}
void Blinky::chase_mode(Position pos)
{
	saw_pac(pos);//will see if pac-man in the field of view.

	if (seen && !scared && !scatter)
	{
		cout << "blinky-chasing";
		Target(pos); //will target pac man until in the vission.
	}
}
char Blinky::getColor()
{
	return 'r';
}

int Blinky::getbx()
{
	return 580;
}
int Blinky::getby()
{
	return 426;
}
//////////////////////////////
Inky::Inky(Position p)
{
	this->pos.x = p.x;
	this->pos.y = p.y;
	ghostPos.x = 1;
	ghostPos.y = 5;
	horg = 14;
	verg = 15;
	color = 'b'; //blue.
	scatter = false;
}
void Inky::scatter_mode()
{
	if (scatter && (ghostPos.x <= 7 && ghostPos.y <= 4))
	{
		cout << "Inky-Scattering.";
		Position s;
		s.x = 1;
		s.y = 27;
		Target(s);
	}
}
void Inky::chase_mode(Position p)
{
	saw_pac(pos);//will see if pac-man in the field of view.
	if (seen && !scared && !scatter)
	{
		pos.x *= 2;
		pos.y *= 2;
		cout << "inky-chasing";
		Target(pos); //will target pac man until in the vission.
	}
}
char Inky::getColor()
{
	return 'b';
}

/////////////////////////////
Clyde::Clyde(Position p)
{
	this->pos.x = p.x;
	this->pos.y = p.y;
	ghostPos.x = 16;
	ghostPos.y = 1;
	scatter = false;
	horg = 15;
	verg = 15;
	color = 'o'; //orange.
}
char Clyde :: getColor()
{
	return 'o';
}
void Clyde::scatter_mode()
{
	if (scatter && (ghostPos.x >= 15 && ghostPos.y <= 6))
	{
		cout << "clyde-Scattering.";
		Position s;
		s.x = 29;
		s.y = 1;
		Target(s);
	}
}
void Clyde::saw_pac(Position p)
{
	if (displacement(p.x, p.y, ghostPos.x, ghostPos.y) > 8 && displacement(p.x, p.y, ghostPos.x, ghostPos.y) < 11)
	{
		seen = true;
		scatter = false;
	}
	else if (displacement(p.x, p.y, ghostPos.x, ghostPos.y) < 8)
	{
		seen = false;
		scatter = true;
	}
	else
	{
		seen = false;
		scatter = true;
	}
}
void Clyde::chase_mode(Position p)
{
	Clyde::saw_pac(p);//will see if pac-man in the field of view.

	if (seen && !scared && !scatter)
	{
		cout << "clyde-chasing";
		Target(p); //will target pac man until in the vission.
	}
}
///////////////
Pinky::Pinky(Position p)
{
	this->pos.x = p.x;
	this->pos.y = p.y;
	ghostPos.x = 18;
	ghostPos.y = 8;
	horg = 13;
	verg = 13;
	scatter = false;
	color = 'p'; //pink.
}
void Pinky::scatter_mode()
{
	if (scatter && (ghostPos.x >= 15 && ghostPos.y >= 6))
	{
		cout << "pinky-Scattering.";
		Position s;
		s.x = 29;
		s.y = 27;
		Target(s);
	}
}
void Pinky::chase_mode(Position pos)
{
	saw_pac(pos);//will see if pac-man in the field of view.

	if (seen && !scared && !scatter)
	{
		pos.x += 5;
		cout << "pinky-chasing";
		Target(pos); //will target pac man until in the vission.
	}
}
char Pinky::getColor()
{
	return 'p';
}
int Pinky::getpx()
{
	return 310;
}
int Pinky::getpy()
{
	return 65;
}
