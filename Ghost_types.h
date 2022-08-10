#pragma once
#include "PlayerPac.h"
#include "Ghost.h"
#include "Ghost_draw.h"

using namespace std;

class Blinky :public Ghost
{
private:
	char color;
	Position pos;//we will store pacman's cordinates here so we can use it for finding the distance.
	/*int bx;
	int by;*/
public:
	int bx;
	int by;
	Blinky(Position pos);
	void initVariables();
	void scatter_mode();
	void chase_mode(Position pos); //agrressive mode for blinky.
	char getColor();
	int getbx();
	int getby();
};
class Pinky : public Ghost
{
private:
	char color;
	Position pos;//we will store pacman's cordinates here so we can use it for finding the distance.
	//Ghost_draw* pink;
public:
	Pinky(Position pos);
	void scatter_mode();
	void chase_mode(Position pos);
	char getColor();
	int getpx();
	int getpy();
	//ambus mode for pinky.
};
class Clyde : public Ghost
{
private:
	char color;
	Position pos;//we will store pacman's cordinates here so we can use it for finding the distance.
	//Ghost_draw* cy;
public:
	Clyde(Position pos);
	char getColor();
	void scatter_mode();
	void saw_pac(Position pos);
	void chase_mode(Position pos); //mode for clyde.
};
class Inky : public Ghost
{
private:
	char color;
	Position pos;//we will store pacman's cordinates here so we can use it for finding the distance.
	//Ghost_draw* in;
	char direction;

public:
	Inky(Position pos);
	void scatter_mode();
	void chase_mode(Position pos); //mode for clyde.
	char getColor();
	//void renderInky();

};