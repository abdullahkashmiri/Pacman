#include "Ghost.h"
using namespace std;
void Ghost::initVariables()
{
	this->ghostPos.x = 10;
	this->ghostPos.y = 8;
	this->direction = 'o';
	this->scatter = false;
	this->seen = false;
	this->scared = false;
}
int Ghost::displacement(int px, int py, int gx, int gy)
{
	return (int)sqrt(pow((px - gx), 2) + pow((py - gy), 2));
}
Ghost::Ghost()
{
	this->initVariables();
}
int Ghost::collide_ghost(bool power, int& pposx, int& pposy, int& ghox, int& ghoy, char& direct, int& x, int& y)
{
	if (!power && (pposx == ghox && pposy == ghoy))
	{
		//pac man will be eaten.
		pposx = 1;//to be changed.
		pposy = 1;
		direct = 'o';
		if (lives != 0)
			lives--;
		return 2;
	}
	else if (power && (pposx == ghox && pposy == ghoy))
	{
		//ghost will be eatten.
		ghox = 1;
		ghoy = 3;
		x = 580;
		y = 426;
		score += 200;
		return 3;
	}
	return 1;
	///issue here not returniing values
}
void Ghost::saw_pac(Position p)
{
	//if distance between ghost and player is <8 then he can see pacman & there is no wall in between.
	if (this->displacement(p.x, p.y, ghostPos.x, ghostPos.y) < 8)
	{
		seen = true;
		scatter = false;
	}
	else
	{
		seen = false;
		scatter = true;
	}
}
void Ghost::set_dir(char a)
{
	direction = a;
}
bool Ghost::up()
{
	if (!is_wall(ghostPos.x, ghostPos.y - 1))
	{
		return true;
	}
	return false;
}
bool Ghost::down()
{
	if (!is_wall(ghostPos.x, ghostPos.y + 1))
	{
		return true;
	}
	return false;
}
bool Ghost::left()
{
	if (!is_wall(ghostPos.x - 1, ghostPos.y))
	{
		return true;
	}
	return false;
}
bool Ghost::right()
{
	if (!is_wall(ghostPos.x + 1, ghostPos.y))
	{
		return true;
	}
	return false;
}
void Ghost::Target(Position target)
{
	if (target.x == ghostPos.x && target.y > ghostPos.y && !down())//for stuck
	{
		stucked = 1;
	}
	if (target.x == ghostPos.x && target.y < ghostPos.y && !up())//for stuck
	{
		stucked = 1;
	}
	if (target.x == ghostPos.x && target.y > ghostPos.y && down())//for non stuck
	{
		stucked = 0;
	}
	if (target.x == ghostPos.x && target.y < ghostPos.y && up())//for non stuck
	{
		stucked = 0;
	}
	if (target.x > ghostPos.x && target.y == ghostPos.y && !right())//for stuck
	{
		stucked = 1;
	}
	if (target.x < ghostPos.x && target.y == ghostPos.y && !left())//for stuck
	{
		stucked = 1;
	}
	if (target.x > ghostPos.x && target.y == ghostPos.y && right())//for  non stuck
	{
		stucked = 0;
	}
	if (target.x < ghostPos.x && target.y == ghostPos.y && left())//for non stuck
	{
		stucked = 0;
	}
	if (target.x > ghostPos.x && right() && stucked == 0)
	{
		set_dir('d');
	}
	else if (target.x < ghostPos.x && left() && stucked == 0)
	{
		set_dir('a');
	}
	else if (target.x == ghostPos.x && target.y != ghostPos.y && stucked == 1)
	{
		if (target.y < ghostPos.y && !up())
		{
			if (left())
			{
				set_dir('a');
			}
			else if (right())
			{
				set_dir('d');
			}
			else if (down())
			{
				set_dir('s');
			}
		}
		else if (target.y > ghostPos.y && !down())
		{
			cout << "phas geya";
			if (left())
			{
				set_dir('a');
			}
			else if (right())
			{
				set_dir('d');
			}
			else if (up())
			{
				set_dir('w');
			}
		}
	}
	if (target.y > ghostPos.y && down() && stucked == 0)
	{
		set_dir('s');
		cout << "down!!";
	}
	else if (target.y < ghostPos.y && up() && stucked == 0)
	{
		set_dir('w');
		cout << "up!!";
	}
	else if (target.x != ghostPos.x && target.y == ghostPos.y && stucked == 1)
	{
		if (target.x < ghostPos.x && !left())
		{
			cout << "phas geya";
			if (up())
			{
				set_dir('w');
			}
			else if (down())
			{
				set_dir('s');
			}
			else if (right())
			{
				set_dir('d');
			}
		}
		else if (target.x > ghostPos.x && !right())
		{
			cout << "phas geya";
			if (up())
			{
				set_dir('w');
			}
			else if (down())
			{
				set_dir('s');
			}
			else if (left())
			{
				set_dir('a');
			}
		}
	}
}
bool Ghost::is_wall(int x, int y)
{
	if (Map[y][x] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
	//cout << "Wall givenn map value" << Map[y][x] << endl;
}
void Ghost::move_decide()
{
	//cout << "Move decide Called" << endl;
	//cout << "MAP val  " << Map[horg][verg] << endl;
	if ((Map[horg + 1][verg] == 1 && direction == 's') || (Map[horg - 1][verg] == 1 && direction == 'w') || (Map[horg][verg + 1] == 1 && direction == 'd') || (Map[horg][verg - 1] == 1 && direction == 'a') || direction == 'o' || (Map[horg][verg + 1] == 6 && direction == 'd') || (Map[horg][verg - 1] == 6 && direction == 'a'))
	{
		// ((Map[horg][verg + 1] == 6 && direction == 'd') || (Map[horg][verg - 1] == 6 && direction == 'a') || direction == 'o')

	//	cout << horg << "  " << verg << endl;
		int u = 0, d = 0, l = 0, r = 0;
		u = rand() % 2;//for randomness in movement
		d = rand() % 2;
		l = rand() % 2;
		r = rand() % 2;
	//	cout << " u " << u << " d " << d << " l " << l << " r " << r << endl;
		if ((Map[horg - 1][verg] != 1) && u < 1)
		{
			direction = 'w';
		}
		else if (Map[horg][verg - 1] != 1 && l < 1)
		{
			direction = 'a';
		}
		else if (Map[horg + 1][verg] != 1 && d < 1)
		{
			direction = 's';
		}
		else if (Map[horg][verg + 1] != 1 && r < 2)
		{
			direction = 'd';
		}
		else
			direction = 'o';
	}
}
void Ghost::move()
{
	//cout << "Moving called";
	if (direction == 's')
	{
		if (Map[horg + 1][verg]!=1)
			horg += 1; //cout << "moving down.";
	}
	else if (direction == 'a')
	{
		if (Map[horg][verg - 1]!=1)
			verg-= 1; //cout << "moving left.";
	}//
	else if (direction == 'd')
	{
		if (Map[horg][verg +1]!=1)
			verg += 1; //cout << "moving right.";
	}
	else if (direction == 'w')
	{
		if (Map[horg - 1][verg]!=1)
			horg -= 1; //cout << "moving up.";
	}
}
char Ghost:: getDirectionFromGhost()
{
	return direction;
}
char Ghost::frighten_mode()
{
	if (scared && back)
	{
		//will move up if direction is down and there is no wall up
		if (direction == 's' && Map[horg-1][verg]!=1)
		{
			direction = 'w';
		}
		//will move right if direction is left and there is no wall right.
		else if (direction == 'a' && Map[horg][verg+1]!=1)
		{
			direction = 'd';
		}
		//will move down if direction is up and there is no wall down
		else if (direction == 'w' && Map[horg+1][verg]!=1)
		{
			direction = 's';
		}
		//will move left if direction is right and there is no wall left.
		else if (direction == 'd' && Map[horg][verg-1]!=1)
		{
			direction = 'a';
		}

		back--;
		//cout << "\n\n\n\n\n\n\nFrighten mode" << endl;
	//	system("pause");
		return 'b';

	}
	return 'c';
}
void Ghost::get_frighten(bool eat_apple)
{
	if (eat_apple)
	{
		scared = true;
		back = 4;
	}
	//cout << "Frighten fun" << endl;
	//cout << "scared" << scared << endl;
	//system("pause");
}


void Ghost::frighten_end(bool& scared, bool& powered,int &fr)
{
	//cout <<"frTimer"<< fr_timer << endl;
	if (fr == 0)
	{
		scared = false;
		powered = false;
	}

}
