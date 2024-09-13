#pragma once
#include "PlayerPac.h"
//#include"Game.h"


class Ghost
{
private:
	//Data Members
	char direction; //direction
	int stucked = 0; //will be one if ghost is stuck while following the target.
	//Game* game;
	//Functions
	void initVariables();
public:
	//Data Memebers
	Position mapPos;

	Position ghostPos;
	int horg;
	int verg;
	bool seen;
	bool scared;
	bool scatter;


	//friend functions
	int collide_ghost(bool power, int& pposx, int& pposy, int& ghox, int& ghoy, char& direct,int &x,int &y);
    int displacement(int, int, int, int);
    void frighten_end(bool&, bool&,int &);

	bool is_wall(int x, int y);

	//Functions

	Ghost();
	//Ghost();
	void Target(Position target);
	void move_decide();
	char getDirectionFromGhost();
	void move();
	char frighten_mode();
	void get_frighten(bool eat_apple);

	virtual void chase_mode(Position) = 0;
	virtual void scatter_mode() = 0;

protected:
	
	virtual void saw_pac(Position p);//pacman's cordinates.
	void set_dir(char a);
	bool up(); //checks if moving up is possible
	bool down(); // checks if moving down is possible
	bool left();// checks if moving left is possible
	bool right();// checks if moving right is possible






};

