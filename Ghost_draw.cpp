#include "Ghost_draw.h"

using namespace std;
void Ghost_draw::initVariables(int x,int y, char col)
{
	this->ghostanimState = IDLE;
	this->ghostmoving = false;
	gPos.x = x;
	gPos.y = y;
	setColor = col;
	direction = 'o';
}
void Ghost_draw::updateagain(int x, int y)
{
	this->gPos.x = 580;
	this->gPos.y = 426;
	this->ghostDraw.setPosition(this->gPos.x, this->gPos.y);
	initSprite();
}
void Ghost_draw::settingcolor(char& a)
{
	setColor = a;
	//cout << "set color" << setColor << endl;
}

void Ghost_draw::fright_end(char &a)
{
	setColor = a;

}
char Ghost_draw:: getcolor()
{
	return setColor;
}
void Ghost_draw::initTexture()
{
	if (!this->ghostSheet.loadFromFile("res/Ghost16.png"))//image loaded
	{
		cout << "Error player texture not loaded\n";
	}
}
void Ghost_draw::initSprite()
{
	this->ghostDraw.setTexture(this->ghostSheet);
	this->ghostDraw.setPosition(this->gPos.x, this->gPos.y);
	this->ghostcurrentFrame = sf::IntRect(0, 0, 16, 16);//cropping png
	this->ghostDraw.setTextureRect(this->ghostcurrentFrame);
	this->ghostDraw.setScale(1.5f, 1.5f);//size of pacman
}
void Ghost_draw::initAnimations()
{
	this->ghostanimationTimer.restart();
}
Ghost_draw::Ghost_draw()
{
	this->initTexture();
	this->initSprite();
	this->initAnimations();
}
Ghost_draw::Ghost_draw(int x,int y,char col)
{
	this->initVariables(x, y, col);
	this->initTexture();
	this->initSprite();
	this->initAnimations();
}
void Ghost_draw::updateMovement()
{
	this->ghostanimState = IDLE;
	if (direction=='a')//left
	{
		this->ghostanimState = MOVING_LEFT;
		this->ghostDraw.move(-2.0f, 0.f);
	}
	else if (direction=='d')//right
	{
		this->ghostanimState = MOVING_RIGHT;
		this->ghostDraw.move(2.0f, 0.f);
	}
	else if (direction=='w')//top
	{
		this->ghostanimState = MOVING_UP;
		this->ghostDraw.move(0.f, -2.0f);
	}
	else if (direction=='s')//down
	{
		this->ghostanimState = MOVING_DOWN;
		this->ghostDraw.move(0.f, 2.0f);
	}
}


void Ghost_draw::updateAnimations()//idle for idle
{
	if (this->ghostanimState == IDLE || this->ghostanimState == MOVING_RIGHT || this->ghostanimState == MOVING_UP || this->ghostanimState == MOVING_LEFT || this->ghostanimState == MOVING_DOWN)
	{
		if (this->ghostanimationTimer.getElapsedTime().asSeconds() >= 0.1f)
		{
			if (setColor == 'b')
			{
				//----------blue----------
				this->ghostcurrentFrame.top = 0;
				this->ghostcurrentFrame.left += 32.f;
				if (this->ghostcurrentFrame.left >= 48.f)
					this->ghostcurrentFrame.left = 32.f;
			}
			if (setColor == 'o')
			{
				//----------orange----------
				this->ghostcurrentFrame.top = 0;
				this->ghostcurrentFrame.left += 48.f;
				if (this->ghostcurrentFrame.left >= 60.f)
					this->ghostcurrentFrame.left = 48.f;
			}
			if (setColor == 'p')
			{
				//----------pink----------
				this->ghostcurrentFrame.top = 0;
				this->ghostcurrentFrame.left += 16.f;
				if (this->ghostcurrentFrame.left >= 32.f)
					this->ghostcurrentFrame.left = 16;
			}
			if (setColor == 'r')
			{
				//----------red----------
				this->ghostcurrentFrame.top = 0;
				this->ghostcurrentFrame.left += 16.f;
				if (this->ghostcurrentFrame.left >= 16.f)
					this->ghostcurrentFrame.left = 0;
			}
			this->ghostanimationTimer.restart();
			this->ghostDraw.setTextureRect(this->ghostcurrentFrame);
		}
	}
}
void Ghost_draw::update()
{
	this->updateMovement();
	this->updateAnimations();
}
void Ghost_draw::setDirection(char dir)
{
	direction = dir;
}
void Ghost_draw::render(sf::RenderTarget& target)
{
	this->update();
	target.draw(this->ghostDraw);
}
Ghost_draw::~Ghost_draw()
{
}
