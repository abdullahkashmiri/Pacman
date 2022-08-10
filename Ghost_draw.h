#include"PlayerPac.h"
//#include "Ghost_types.h"

#pragma once
//enum PLAYER_ANIMATION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, MOVING_DOWN };
class Ghost_draw
{
private: 
	sf::Sprite ghostDraw;
	sf::Texture ghostSheet;
	bool ghostmoving;
	sf::Clock ghostanimationTimer;
	short ghostanimState;
	sf::IntRect ghostcurrentFrame;

	void initTexture();
	void initSprite();
	void initAnimations();
public:
	Position gPos;

	char setColor;
	char direction;
	void settingcolor(char & a);
	void fright_end(char& a);
	char getcolor();
	Ghost_draw();

	void initVariables(int, int, char);
	void updateagain(int x, int y);
	Ghost_draw(int,int,char);
	void updateMovement();
	void updateAnimations();
	void update();
	void setDirection(char dir);
	void render(sf::RenderTarget& target);

	~Ghost_draw();

};

