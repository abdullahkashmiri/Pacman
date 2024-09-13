#pragma once
#include "PlayerPac.h"
#include"Ghost_draw.h"
#include "Ghost_types.h"



class Game
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	PlayerPac* pac;
	bool endGame;
	sf::Event ev;
	sf::Texture wall;
	sf::Texture dot;
	sf::Texture gate;
	sf::Sprite spriteWall;
	sf::Sprite spriteDot;
	sf::Sprite spriteGate;
	sf::Sprite spriteEnergizer;
	sf::Font font;
	sf::Text scoreText;
	sf::Text scoreVal;
	sf::Text pacmanText;
	sf::SoundBuffer chomp;
	sf::SoundBuffer start;
	sf::Sound soundChomp;
	sf::Sound soundStart;


	int check;
	int index_check;
	/////////////////////



	Ghost_draw* blinkydraw;
	Ghost_draw* pinkydraw;
	Ghost_draw* inkydraw;
	Ghost_draw *clydedraw;



	Blinky* blinky;
	Pinky* pinky;
	Clyde* clyde;
	Inky* inky;
	long frame;
	Position gameG_Pos;
	void frame_rt_AllGhost();
	void Blinky_Decide();
	void pinky_Decide();
	void inky_Decide();
	void clyde_Decide();
	void setGhost();
	//..................
	void ghostMoveDecide();
	void ghostAllMove();
	void checkGhostCollide();
	void chaseAllGhosts();
	void scatterAllGhost();
	void frighten_endAllghost();
	void movingGhost();

	char direction;
	int pacx ;
	int pacy ;

	void initVariables();
	void initWindow();


public:
	//int** Map;
	void eatenCheck();
	//Constructors & Destructors
	Game();
	//Game(int map[31][28]);
	~Game();


	//Accessors

	//Modifiers

	//Functions
	const bool running() const;
	void pollEvents();
	void updatePlayer();
	void renderPlayer();
	void renderghost();

	void initTexture();
	void initSprite();
	void initFont();
	void initSound();
	void frighten_end(bool& scared, bool& powered);
	void DrawMap();
	void update();
	void render();
	void move();
	void collectDot(int x,int y);
	const sf::RenderWindow& getWindow() const;


};

