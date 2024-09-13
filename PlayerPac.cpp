#include "PlayerPac.h"
using namespace std;

void PlayerPac::initVariables()
{
	this->animStatepac = IDLE;
	this->pacmoving = false;
	pos.x = 250;
	pos.y = 65;
	powered = false;
	this->pacman.setPosition(this->pos.x, this->pos.y);
	
}
void PlayerPac::initTexture()
{
	if (!this->pacsheet.loadFromFile("res/Pacman.png"))
	{
		cout << "Load failed " << endl;
		system("pause");
	}
}
void PlayerPac::initSprite()
{
	this->pacman.setTexture(this->pacsheet);
	this->currentFramepac = sf::IntRect(0, 0, 16, 16);//cropping png
	this->pacman.setTextureRect(this->currentFramepac);
	this->pacman.setScale(1.5f, 1.5f);//size of pacman
}
void PlayerPac::initAnimations()
{
	this->animationTimerpac.restart();
}
//
//void PlayerPac::collide_ghost(bool, int&, int&, int&, int&, char&)
//{
//}
int PlayerPac::displacement(int px, int py, int gx, int gy)
{
	return (int)sqrt(pow((px - gx), 2) + pow((py - gy), 2));
}
PlayerPac::PlayerPac()
{
	if (score <= 0)
	{
		this->initVariables();
		this->initTexture();
		this->initSprite();
		this->initAnimations();
	}
}
void PlayerPac::updateMovement()
{
	this->animStatepac = IDLE;
	if (direction == 'A')//left
	{
		this->animStatepac = MOVING_LEFT;
		this->pacman.move(-2.0f, 0.f);
	}
	else if (direction =='D')//right
	{
		this->animStatepac = MOVING_RIGHT;
		this->pacman.move(2.0f, 0.f);
	}
	else if (direction == 'W')//top
	{
		this->animStatepac = MOVING_UP;
		this->pacman.move(0.f, -2.0f);
	}
	else if (direction == 'S')//down
	{
		this->animStatepac = MOVING_DOWN;
		this->pacman.move(0.f, 2.0f);
	}
}

void PlayerPac::updateAnimations()
{
	if (this->animStatepac == IDLE)
	{
		if (this->animationTimerpac.getElapsedTime().asSeconds() >= 0.05f)
		{
			this->currentFramepac.top = 0;
			this->currentFramepac.left += 16.f;
			if (this->currentFramepac.left >= 16.f)
				this->currentFramepac.left = 0;
			this->animationTimerpac.restart();
			this->pacman.setTextureRect(this->currentFramepac);
		}
	}
	else if (this->animStatepac == MOVING_RIGHT)
	{
		if (this->animationTimerpac.getElapsedTime().asSeconds() >= 0.05f)
		{
			this->currentFramepac.top = 0;
			this->currentFramepac.left += 16.f;
			if (this->currentFramepac.left >= 96.f)
				this->currentFramepac.left = 0;
			this->animationTimerpac.restart();
			this->pacman.setTextureRect(this->currentFramepac);
		}
	}
	else if (this->animStatepac == MOVING_UP)
	{
		if (this->animationTimerpac.getElapsedTime().asSeconds() >= 0.05f)
		{
			this->currentFramepac.top = 16;
			this->currentFramepac.left += 16.f;
			if (this->currentFramepac.left >= 96.f)
				this->currentFramepac.left = 0;
			this->animationTimerpac.restart();
			this->pacman.setTextureRect(this->currentFramepac);
		}
	}
	else if (this->animStatepac == MOVING_LEFT)
	{
		if (this->animationTimerpac.getElapsedTime().asSeconds() >= 0.05f)
		{
			this->currentFramepac.top = 32;
			this->currentFramepac.left += 16.f;
			if (this->currentFramepac.left >= 96.f)
				this->currentFramepac.left = 0;
			this->animationTimerpac.restart();
			this->pacman.setTextureRect(this->currentFramepac);
		}
	}
	else if (this->animStatepac == MOVING_DOWN)
	{
		if (this->animationTimerpac.getElapsedTime().asSeconds() >= 0.05f)
		{
			this->currentFramepac.top = 48;
			this->currentFramepac.left += 16.f;
			if (this->currentFramepac.left >= 96.f)
				this->currentFramepac.left = 0;
			this->animationTimerpac.restart();
			this->pacman.setTextureRect(this->currentFramepac);
		}
	}
}
void PlayerPac::update()
{
	this->updateMovement();
	this->updateAnimations();
}
void PlayerPac::setDirection(char dir)
{
	direction = dir;
}
void PlayerPac::render(sf::RenderTarget& target )
{
	update();
	target.draw(this->pacman);
}
PlayerPac::~PlayerPac()
{
}

void PlayerPac:: frighten_end(bool& scared, bool& powered)
{
	if (fr_timer == 0)
	{
		scared = false;
		powered = false;
	}
}
