#include "Game.h"


using namespace std;
void Game::frame_rt_AllGhost()
{
	if (Blinky_fr_rate == 0)
	{
		this->Blinky_Decide();
		this->blinkydraw->setDirection(this->blinky->getDirectionFromGhost());
		Blinky_fr_rate = 15;
	}
	if (Pinky_fr_rate == 0)
	{
		this->pinky_Decide();
		this->pinkydraw->setDirection(this->pinky->getDirectionFromGhost());
		Pinky_fr_rate = 15;
	}
	if (Inky_fr_rate == 0)
	{
		this->inky_Decide();
		this->inkydraw->setDirection(this->inky->getDirectionFromGhost());
		Inky_fr_rate = 15;
	}
	if (Clyde_fr_rate == 0)
	{
		this->clyde_Decide();
		this->clydedraw->setDirection(this->clyde->getDirectionFromGhost());
		Clyde_fr_rate = 15;
	}
}
void Game::Blinky_Decide()
{
	if (fr_timer > 0)
	{
		fr_timer--;
	}
	pac->pos.x = pacx;
	pac->pos.y = pacy;
	//cout << "Blinky Decide Called" << endl;
	blinky->move_decide();
	if (blinky->frighten_mode() == 'b')
	{
		char b = 'b';
		blinkydraw->settingcolor(b);
	}
	if(fr_timer==0)
	{
		blinkydraw->setColor = 'r';
	}

	blinky->frighten_end(blinky->scared, pac->powered, fr_timer);

	blinky->scatter_mode();
	pac->pos.x = pacx;
	pac->pos.y = pacy;
//	blinky->chase_mode(pac->pos);

	this->blinkydraw->setDirection(this->blinky->getDirectionFromGhost());




	blinky->move();


	//blinky->collide_ghost(pac->powered, pac->pos.x, pac->pos.y, blinky->horg, blinky->verg, pac->direction);
	//blinky->chase_mode(pac->pos);
	//blinky->scatter_mode();
	//pac->frighten_end(blinky->scared, pac->powered);
	//blinky->get_frighten(pac->powered);
	

}
void Game::pinky_Decide()
{
	//cout << "Pinky Decide Called" << endl;
	pinky->move_decide();
	if (pinky->frighten_mode() == 'b')
	{
		cout << "true" << endl;
		char b = 'b';
	pinkydraw->settingcolor(b);
	}
	if (fr_timer == 0)
	{
		pinkydraw->setColor = 'p';
	}
	
	pinky->frighten_end(pinky->scared, pac->powered, fr_timer);
	pinky->scatter_mode();

	this->pinkydraw->setDirection(this->pinky->getDirectionFromGhost());
	pinky->move();

	//this->pinkydraw->setDirection(this->pinky->getDirectionFromGhost());
	//pac->collide_ghost(pac->powered, pac->pos.x, pac->pos.y, pinky->ghostPos.x, pinky->ghostPos.y, pac->direction);
	/*pinky->chase_mode(pac->pos);
	pinky->scatter_mode();
	pac->frighten_end(pinky->scared, pac->powered);
	*/
}
void Game::inky_Decide()
{
	//cout << "inky Decide Called" << endl;
	inky->move_decide();
	if (inky->frighten_mode() == 'b')
	{
		cout << "true" << endl;
		char b = 'b';
		inkydraw->settingcolor(b);
	}
	if (fr_timer == 0)
	{
		inkydraw->setColor = 'b';
	}

	inky->frighten_end(inky->scared, pac->powered, fr_timer);
	inky->scatter_mode();

	this->inkydraw->setDirection(this->inky->getDirectionFromGhost());
	inky->move();

	//this->inkydraw->setDirection(this->inky->getDirectionFromGhost());
	//pac->collide_ghost(pac->powered, pac->pos.x, pac->pos.y, inky->ghostPos.x, inky->ghostPos.y, pac->direction);
	//inky->chase_mode(pac->pos);
	//inky->scatter_mode();
	//pac->frighten_end(inky->scared, pac->powered);
}
void Game::clyde_Decide()
{
	//cout << "inky Decide Called" << endl;
	clyde->move_decide();
	if (clyde->frighten_mode() == 'b')
	{
		cout << "true" << endl;
		char b = 'b';
		clydedraw->settingcolor(b);
	}
	if (fr_timer == 0)
	{
		clydedraw->setColor = 'o';
	}

	clyde->frighten_end(clyde->scared, pac->powered, fr_timer);
	clyde->scatter_mode();

	this->clydedraw->setDirection(this->clyde->getDirectionFromGhost());
	clyde->move();
	//this->clydedraw->setDirection(this->clyde->getDirectionFromGhost());
	/*pac->collide_ghost(pac->powered, pac->pos.x, pac->pos.y, clyde->ghostPos.x, clyde->ghostPos.y, pac->direction);
	clyde->chase_mode(pac->pos);
	clyde->scatter_mode();
	pac->frighten_end(clyde->scared, pac->powered);*/
}
void Game::setGhost()
{
	//if(fr_rate==0)
	//blinkydraw->initVariables(blinky->getbx(), blinky->getby(), blinky->getColor());
    //ghostdraw->initVariables(pinky->getpx(), pinky->getpy(), pinky->getColor());
	//ghostdraw->initVariables(blinky->getbx(), blinky->getby(), blinky->getColor());
	//ghostdraw->initVariables(blinky->getbx(), blinky->getby(), blinky->getColor());
}

void Game::ghostMoveDecide()
{
	
}
void Game::ghostAllMove()
{
	this->setGhost();
}
void Game::checkGhostCollide()
{

}
void Game::chaseAllGhosts()
{
}
void Game::scatterAllGhost()
{
}
void Game::frighten_endAllghost()
{

}
void Game::movingGhost()
{
	//cout << "Moving all fun ghost activated" << endl;
		this->ghostMoveDecide();
		this->ghostAllMove();
		this->setGhost();
		this->checkGhostCollide();
		this->chaseAllGhosts();
		this->scatterAllGhost();
		this->frighten_endAllghost();
}
void Game::initVariables()
{
	this->endGame = false;
	this->pac = new PlayerPac;
	//this->Map = NULL;
	this->blinkydraw = new Ghost_draw(580, 426, blinky->getColor());
	this->pinkydraw = new Ghost_draw(610, 426, pinky->getColor());
	this->inkydraw = new Ghost_draw(670, 456, inky->getColor());
	this->clydedraw = new Ghost_draw(670, 486, clyde->getColor());
	this->blinky = new Blinky(pac->pos);
	this->pinky = new Pinky(pac->pos);
	this->clyde = new Clyde(pac->pos);
	this->inky = new Inky(pac->pos);
	this->frame = 0;
}
void Game::initWindow()
{
	this->videoMode.height = 1000;
	this->videoMode.width = 1280;
	this->window = new sf::RenderWindow(this->videoMode, "PAC-MAN GALAXY", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	pacx = 1;
	pacy = 1;
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
}
Game::~Game()
{
	delete this->window;
	delete this->pac;
	//delete this->Map;
}
//Functions
const bool Game::running() const
{
	return this->window->isOpen();
}
void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		while (this->window->pollEvent(this->ev))
		{
			if (this->ev.type == sf::Event::Closed)
				window->close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window->close();
		}
	}
	this->updatePlayer();
}
void Game::updatePlayer()
{
	this->pac->update();
}
void Game::renderPlayer()
{
	this->pac->setDirection(direction);
	this->pac->render(*this->window);
}
void Game::renderghost()
{
	//Rendering All Ghost
	//this->pac->setDirection(direction);
	this->blinkydraw->render(*this->window);
	this->pinkydraw->render(*this->window);
	this->inkydraw->render(*this->window);
	this->clydedraw->render(*this->window);
}
void Game::initTexture()
{
	if (!this->wall.loadFromFile("res/wall.png"))
	{
		cout << "Load failed::Player::inittexture. " << endl;
		system("pause");
	}
	if (!this->dot.loadFromFile("res/dot.jpg"))
	{
		cout << "Load failed::Player::inittexture. " << endl;
		system("pause");
	}
	if (!this->gate.loadFromFile("res/dot.jpg"))
	{
		cout << "Load failed::Player::inittexture. " << endl;
		system("pause");
	}
}
void Game::initSprite()
{
	this->spriteWall.setTexture(this->wall);
	this->spriteWall.setTextureRect(sf::IntRect(0, 0, 25, 20));
	this->spriteDot.setTexture(this->dot);
	this->spriteDot.setTextureRect(sf::IntRect(0, 0, 5, 5));
	this->spriteGate.setTexture(this->gate);
	this->spriteGate.setTextureRect(sf::IntRect(0, 0, 30, 5));
	this->spriteEnergizer.setTexture(this->dot);
	this->spriteEnergizer.setTextureRect(sf::IntRect(0, 0, 13, 13));
}
void Game::DrawMap()
{
	//cout << "Drawing MAP" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (Map[i][j] == 1)
			{
				this->spriteWall.setPosition(sf::Vector2f((j * cell) + wallxspc, (i * cell) + wallyspc));
				this->window->draw(this->spriteWall);
			}
			if (Map[i][j] == 2)
			{
				this->spriteDot.setPosition(sf::Vector2f((j * cell) + dotxspc, (i * cell) + dotyspc));
				this->window->draw(this->spriteDot);
			}
			if (Map[i][j] == 3)
			{
				this->spriteEnergizer.setPosition(sf::Vector2f((j * cell) + dotxspc - 4 , (i * cell) + dotyspc - 4));
				this->window->draw(this->spriteEnergizer);
			}
			if (Map[i][j] == 9)
			{
				this->spriteGate.setPosition(sf::Vector2f((j * cell) + dotxspc - 12, (i * cell) + dotyspc - 9));
				this->window->draw(this->spriteGate);
			}
		}
	}
	stringstream ss;
	ss << score;
	scoreVal.setString(ss.str());
	this->window->draw(this->scoreText);
	this->window->draw(this->scoreVal);
	this->window->draw(this->pacmanText);
}
void Game::initFont()
{
	if (!font.loadFromFile("fonts/fontacme.ttf"))
	{
		cout << "Load failed " << endl;
		system("pause");
	}
	this->scoreText.setFont(this->font);
	this->scoreText.setCharacterSize(38);
	this->scoreText.setStyle(sf::Text::Bold);
	this->scoreText.setString("Score : ");
	this->scoreText.setPosition(20, 30);
	this->scoreVal.setFont(this->font);
	this->scoreVal.setCharacterSize(38);
	this->scoreVal.setStyle(sf::Text::Bold);
	this->scoreVal.setPosition(150, 30);
	this->pacmanText.setFont(this->font);
	this->pacmanText.setCharacterSize(32);
	this->pacmanText.setStyle(sf::Text::Bold);
	this->pacmanText.setString("SASTA PAC-MAN ");
	this->pacmanText.setPosition(520, 0);
}
void Game::update()
{
	this->pollEvents();
}
void Game::render()
{
	if (score ==-1)
		this->move();
	direction = 'O';
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)))
		{
			if (Map[pacx][pacy - 1] != 1 && Map[pacx][pacy - 1] != 9 )
			{
				for (int i = 0; i < 15; i++)
				{
					this->direction = 'A';
					this->move();
					if (i == 7 && (Map[pacx][pacy - 1] == 2 || Map[pacx ][pacy-1] == 3))
						this->collectDot(pacx, pacy - 1);
				}
				this->pacy--;
				this->direction = 'O';
			}
			this->move();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)))
		{
			if (Map[pacx][pacy + 1] != 1 && Map[pacx][pacy + 1] != 9)
			{
				for (int i = 0; i < 15; i++)
				{
				this->direction = 'D';
					this->move();
					if (i == 7 &&( Map[pacx][pacy + 1] == 2 || Map[pacx ][pacy+1] == 3))
						this->collectDot(pacx, pacy + 1);	
				}
				this->pacy++;
				this->direction = 'O';
			}
			this->move();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)))
		{
			if (Map[pacx + 1][pacy] != 1 && Map[pacx + 1][pacy] != 9 )
			{
				for (int i = 0; i < 15; i++)
				{
					this->direction = 'S';
					this->move();

					if (i == 7 && (Map[pacx + 1][pacy] == 2 || Map[pacx + 1][pacy] == 3))
						this->collectDot(pacx + 1, pacy);
				}
				this->pacx++;
				this->direction = 'O';
			}
			this->move();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)))
		{
			if (Map[pacx - 1][pacy] != 1 && Map[pacx - 1][pacy] != 9 )
			{
				for (int i = 0; i < 15; i++)
				{
					this->direction = 'W';
					this->move();
					if (i == 7 &&( Map[pacx - 1][pacy] == 2 || Map[pacx - 1][pacy] == 3))
						collectDot(pacx - 1, pacy);
				}
				this->pacx--;
				this->direction = 'O';
			}
			this->move();
		}
	}
}

void Game::eatenCheck()
{
	pac->pos.x = pacx;
	pac->pos.y = pacy;
	index_check = blinky->collide_ghost(pac->powered, pacx, pacy, blinky->horg, blinky->verg, pac->direction, blinkydraw->gPos.x, blinkydraw->gPos.y);
	if (index_check == 2)
	{
		pac->initVariables();
	}
	else if (index_check == 3)
	{
		blinkydraw->updateagain(blinkydraw->gPos.x, blinkydraw->gPos.y);
		blinkydraw->setDirection('o');
		blinky->horg = 13;
		blinky->verg = 12;
	}

	index_check = clyde->collide_ghost(pac->powered, pacx, pacy, clyde->horg, clyde->verg, pac->direction, clydedraw->gPos.x, clydedraw->gPos.y);
	if (index_check == 2)
	{
		pac->initVariables();
	}
	else if (index_check == 3)
	{
		clydedraw->updateagain(clydedraw->gPos.x, clydedraw->gPos.y);
		clydedraw->setDirection('o');
		clyde->horg = 13;
		clyde->verg = 12;
	}

	index_check = pinky->collide_ghost(pac->powered, pacx, pacy, pinky->horg, pinky->verg, pac->direction, pinkydraw->gPos.x, pinkydraw->gPos.y);
	if (index_check == 2)
	{
		pac->initVariables();
	}
	else if (index_check == 3)
	{
		pinkydraw->updateagain(pinkydraw->gPos.x, pinkydraw->gPos.y);
		pinkydraw->setDirection('o');
		pinky->horg = 13;
		pinky->verg = 12;
	}

	index_check = inky->collide_ghost(pac->powered, pacx, pacy, inky->horg, inky->verg, pac->direction, inkydraw->gPos.x, inkydraw->gPos.y);
	if (index_check == 2)
	{
		pac->initVariables();
	}
	else if (index_check == 3)
	{
		inkydraw->updateagain(inkydraw->gPos.x, inkydraw->gPos.y);
		inkydraw->setDirection('o');
		inky->horg = 13;
		inky->verg = 12;
	}

}
void Game::move()
{
	if(Blinky_fr_rate>0)
	Blinky_fr_rate--;
	if (Pinky_fr_rate > 0)
		Pinky_fr_rate--;
	if (Inky_fr_rate > 0)
		Inky_fr_rate--;
	if (Clyde_fr_rate > 0)
		Clyde_fr_rate--;
	

	cout << "Pac power" << pac->powered << endl;
	
	this->window->clear();
	this->eatenCheck();
	this->frame_rt_AllGhost();
	if(score==-1)
	{
		this->initTexture();
		this->initFont();
		this->initSprite();
		this->initSound();
	}
	this->movingGhost();//All ghost moving
	this->DrawMap();
	this->renderPlayer();//image of player
	this->renderghost();
	this->frame++;
	this->window->display();
}
void Game::collectDot(int x, int y)
{
	if (Map[x][y] == 2)
		score++;
	else
	{
		score += 10;
		pac->powered = true;
		back = true;
		fr_timer += 50;//frighten time
		pinky->get_frighten(pac->powered);
		blinky->get_frighten(pac->powered);
		inky->get_frighten(pac->powered);
		clyde->get_frighten(pac->powered);
		cout << "Collectdot" << pac->powered << endl;

	}
	Map[x][y] = 0;
	this->soundChomp.play();
}
const sf::RenderWindow& Game::getWindow() const
{
	// TODO: insert return statement here
	return *this->window;
}
void Game::initSound()
{
	if (!this->chomp.loadFromFile("sounds/pacman_chomp.wav"))
	{
		cout << "Load failed " << endl;
		system("pause");
	}
	if (!this->start.loadFromFile("sounds/pacman_beginning.wav"))
	{
		cout << "Load failed " << endl;
		system("pause");
	}
	this->soundChomp.setBuffer(chomp);
	this->soundStart.setBuffer(start);
	if (score == -1)
	{
		this->soundStart.play();
		score++;
	}
}
//
//void Game::frighten_end(bool& scared, bool& powered)
//{
//	cout << "frTimer" << fr_timer << endl;
//	if (fr_timer == 0)
//	{
//		scared = false;
//		powered = false;
//		cout << "Scared" << scared << endl;
//		cout << "Powered" << powered << endl;
//	}
//
//}