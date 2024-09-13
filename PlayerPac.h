#pragma once
#include <iostream>
#include<ctime>
#include<sstream>
#include <conio.h>
#include <math.h>



#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

enum PLAYER_ANIMATION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, MOVING_DOWN };

//Global Variables

const int rows = 31;
const int cols = 28;
const int cell = 30;
const int wallxspc = 220;
const int wallyspc = 35;
const int dotxspc = 230;
const int dotyspc = 45;
static int score = -1;
static int lives = 3;
static int fr_timer = 0;
//static bool back = false;
static int back = 0;
static int apple[4][2] = { {3,1},{3,26},{23,1}, {23,27} };

static int Blinky_fr_rate = 0;
static int Pinky_fr_rate = 0;
static int Inky_fr_rate = 0;
static int Clyde_fr_rate = 0;
//INITILLIZING MAP


static int Map[rows][cols] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//1
	{1,0,2,2,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,2,2,2,1},//2
	{1,2,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,1,1,2,1},//3
	{1,3,1,0,0,1,2,1,0,0,0,1,2,1,1,2,1,0,0,0,1,2,1,0,0,1,3,1},//4
	{1,2,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,1,1,2,1},//5
	{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},//6
	{1,2,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,2,1},//7
	{1,2,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,2,1},//8
	{1,2,2,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,2,2,1},//9
	{1,1,1,1,1,1,2,1,1,1,1,1,0,1,1,0,1,1,1,1,1,2,1,1,1,1,1,1},//10
	{0,0,0,0,0,1,2,1,1,1,1,1,0,1,1,0,1,1,1,1,1,2,1,0,0,0,0,0},//11
	{0,0,0,0,0,1,2,1,1,0,0,0,0,0,0,0,0,0,0,1,1,2,1,0,0,0,0,0},//12
	{0,0,0,0,0,1,2,1,1,0,1,1,9,9,9,9,1,1,0,1,1,2,1,0,0,0,0,0},//13
	{1,1,1,1,1,1,2,1,1,0,1,0,0,0,6,0,0,1,0,1,1,2,1,1,1,1,1,1},//14
	{7,0,0,0,0,0,2,0,0,0,1,0,0,0,6,0,0,1,0,0,0,2,0,0,0,0,0,7},//15
	{1,1,1,1,1,1,2,1,1,0,1,0,0,0,6,0,0,1,0,1,1,2,1,1,1,1,1,1},//16
	{0,0,0,0,0,1,2,1,1,0,1,1,1,1,1,1,1,1,0,1,1,2,1,0,0,0,0,0},//17
	{0,0,0,0,0,1,2,1,1,0,0,0,0,0,0,0,0,0,0,1,1,2,1,0,0,0,0,0},//18
	{0,0,0,0,0,1,2,1,1,0,1,1,1,1,1,1,1,1,0,1,1,2,1,0,0,0,0,0},//19
	{1,1,1,1,1,1,2,1,1,0,1,1,1,1,1,1,1,1,0,1,1,2,1,1,1,1,1,1},//20
	{1,2,2,2,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,2,2,2,1},//21
	{1,2,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,1,1,2,1},//22
	{1,2,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,1,1,2,1},//23
	{1,3,2,2,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,2,2,3,1},//24
	{1,1,1,2,1,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,1,2,1,1,1},//25
	{1,1,1,2,1,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,1,2,1,1,1},//26
	{1,2,2,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,2,2,1},//27
	{1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,2,1},//28
	{1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,2,1},//29
	{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},//30
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };//31


struct Position
{
	int x;
	int y;
};

class PlayerPac
{
private:
	sf::Sprite pacman;
	sf::Texture pacsheet;
	bool pacmoving;
	sf::Clock animationTimerpac;
	short animStatepac;
	sf::IntRect currentFramepac;
	//Game* g;
	/*int px;
	int py;*/
	//Game* g;

	void initTexture();
	void initSprite();
	void initAnimations();

	
public:
	void initVariables();

	//friends function
	//void collide_ghost(bool, int&, int&, int&, int&, char&);
    int displacement(int, int, int, int);
	void frighten_end(bool&, bool&);

	char direction;

	//char direct;
	bool powered;
	Position pos;
	//bool scared;

	PlayerPac();
	void updateMovement();
	void updateAnimations();

	void update();
	void setDirection(char dir);
	void render(sf::RenderTarget& target);
	~PlayerPac();



};

