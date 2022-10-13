//#include<iostream>
//#include<sstream>
//#include<SFML/Graphics.hpp>
//#include<SFML/Audio.hpp>
////#include<dos.h>
////#include<windows.h>
//
//using namespace std;
//
//const int rows = 31;
//const int cols = 28;
//const int cell = 30;
//const int wallxspc = 220;
//const int wallyspc = 35;
//const int dotxspc = 230;
//const int dotyspc = 45;
//int pacx = 1;
//int pacy = 1;
//static int score = 0;
//
//
//int main()
//{
//
//	sf::RenderWindow window(sf::VideoMode(1280, 1000), "SASTA PAC-MAN");
//	window.setFramerateLimit(60);
//
//	//int just_once_dummy = 0;
//
//
//	sf::Texture wall;
//	if (!wall.loadFromFile("res/wall.png"))
//	{
//		cout << "Load failed " << endl;
//		system("pause");
//		return 0;
//
//	}
//	sf::Texture dot;
//	if (!dot.loadFromFile("res/dot.jpg"))
//	{
//		cout << "Load failed " << endl;
//		system("pause");
//		return 0;
//
//	}
//	sf::Texture gate;
//	if (!gate.loadFromFile("res/dot.jpg"))
//	{
//		cout << "Load failed " << endl;
//		system("pause");
//		return 0;
//
//	}
//	sf::Texture space;
//	if (!space.loadFromFile("res/space.jpg"))
//	{
//		cout << "Load failed " << endl;
//		system("pause");
//		return 0;
//	}
//	sf::Font font;
//	if (!font.loadFromFile("fonts/fontacme.ttf"))
//	{
//		cout << "Load failed " << endl;
//		system("pause");
//		return 0;
//	}
//	sf::SoundBuffer chomp;
//
//	if (!chomp.loadFromFile("pacman_chomp.wav"))
//	{
//		cout << "Load failed " << endl;
//		system("pause");
//		return 0;
//	}
//
//	sf::Sound soundChomp;
//	soundChomp.setBuffer(chomp);
//
//
//	sf::SoundBuffer start;
//
//	if (!start.loadFromFile("pacman_beginning.wav"))
//	{
//		cout << "Load failed " << endl;
//		system("pause");
//		return 0;
//	}
//
//	sf::Sound soundStart;
//	soundStart.setBuffer(start);
//
//	soundStart.play();
//	
//
//	/////////////
//	
//	//sf::Time micro = sf::microseconds(10000);
//	//sf::Time milli = sf::milliseconds(10);
//	//sf::Time second = sf::seconds(0.01f);
//	
//	//cout << second.asSeconds();
//    //sf::Clock clock;
//	////////////////
//
//	sf::Text scoreText;
//	scoreText.setFont(font);
//	scoreText.setCharacterSize(32);
//	//scoreText.setColor(sf::Color::Red);
//	scoreText.setStyle(sf::Text::Bold);
//	scoreText.setString("Score : ");
//	scoreText.setPosition(20, 30);
//
//	//sf::Text pacmanText;
//	//pacmanText.setFont(font);
//	//pacmanText.setCharacterSize(32);
//	////scoreText.setColor(sf::Color::Red);
//	//pacmanText.setStyle(sf::Text::Bold);
//	//pacmanText.setString("SASTA PAC-MAN ");
//	//pacmanText.setPosition(520, 450);
//
//	
//
//	sf::Text scoreVal;
//	scoreVal.setFont(font);
//	scoreVal.setCharacterSize(32);
//
//	scoreVal.setStyle(sf::Text::Bold);
//	scoreVal.setPosition(120, 30);
//
//	
//
//	int map[rows][cols] = {
//		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//1
//		{1,0,2,2,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,2,2,2,1},//2
//		{1,2,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,1,1,2,1},//3
//		{1,2,1,0,0,1,2,1,0,0,0,1,2,1,1,2,1,0,0,0,1,2,1,0,0,1,2,1},//4
//		{1,2,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,1,1,2,1},//5
//		{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},//6
//		{1,2,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,2,1},//7
//		{1,2,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,2,1},//8
//		{1,2,2,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,2,2,1},//9
//		{1,1,1,1,1,1,2,1,1,1,1,1,0,1,1,0,1,1,1,1,1,2,1,1,1,1,1,1},//10
//		{0,0,0,0,0,1,2,1,1,1,1,1,0,1,1,0,1,1,1,1,1,2,1,0,0,0,0,0},//11
//		{0,0,0,0,0,1,2,1,1,0,0,0,0,0,0,0,0,0,0,1,1,2,1,0,0,0,0,0},//12
//		{0,0,0,0,0,1,2,1,1,0,1,1,1,9,9,1,1,1,0,1,1,2,1,0,0,0,0,0},//13
//		{1,1,1,1,1,1,2,1,1,0,1,0,0,0,0,0,0,1,0,1,1,2,1,1,1,1,1,1},//14
//		{0,0,0,0,0,0,2,0,0,0,1,0,0,0,0,0,0,1,0,0,0,2,0,0,0,0,0,0},//15
//		{1,1,1,1,1,1,2,1,1,0,1,0,0,0,0,0,0,1,0,1,1,2,1,1,1,1,1,1},//16
//		{0,0,0,0,0,1,2,1,1,0,1,1,1,1,1,1,1,1,0,1,1,2,1,0,0,0,0,0},//17
//		{0,0,0,0,0,1,2,1,1,0,0,0,0,0,0,0,0,0,0,1,1,2,1,0,0,0,0,0},//18
//		{0,0,0,0,0,1,2,1,1,0,1,1,1,1,1,1,1,1,0,1,1,2,1,0,0,0,0,0},//19
//		{1,1,1,1,1,1,2,1,1,0,1,1,1,1,1,1,1,1,0,1,1,2,1,1,1,1,1,1},//20
//		{1,2,2,2,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,2,2,2,1},//21
//		{1,2,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,1,1,2,1},//22
//		{1,2,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,1,1,2,1},//23
//		{1,2,2,2,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,2,2,2,1},//24
//		{1,1,1,2,1,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,1,2,1,1,1},//25
//		{1,1,1,2,1,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,1,2,1,1,1},//26
//		{1,2,2,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,2,2,1},//27
//		{1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,2,1},//28
//		{1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,2,1},//29
//		{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},//30
//		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };//31
//
//	/////////////////////////////
//
//	sf::CircleShape circ;
//	sf::Vector2f circlePosition(253, 67);
//	circ.setPosition(circlePosition);
//	circ.setRadius(10);
//	circ.setFillColor(sf::Color::Yellow);
//
//	//////////////////////////////
//	sf::Sprite spriteSpace;
//	spriteSpace.setTexture(space);
//	spriteSpace.setTextureRect(sf::IntRect(0, 0, 30, 30));
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//		//handle all events
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//				window.close();
//		}
//
//		sf::Sprite spriteWall;
//		spriteWall.setTexture(wall);
//		spriteWall.setTextureRect(sf::IntRect(0, 0, 25, 20));
//		sf::Sprite spriteDot;
//		spriteDot.setTexture(dot);
//		spriteDot.setTextureRect(sf::IntRect(0, 0, 5, 5));
//
//		sf::Sprite spriteGate;
//		spriteGate.setTexture(gate);
//		spriteGate.setTextureRect(sf::IntRect(0, 0, 30, 5));
//
//		window.clear();
//		window.draw(circ);
//		//////////////////////
//
//
//		stringstream ss;
//		ss << score;
//		scoreVal.setString(ss.str());
//
//		/*ss << score;
//		scoreVal.setString(ss.str());*/
//		window.draw(scoreText);
//		window.draw(scoreVal);
//
//		///////////////////////////
//
//		sf::Text pacmanText;
//		pacmanText.setFont(font);
//		pacmanText.setCharacterSize(32);
//		//scoreText.setColor(sf::Color::Red);
//		pacmanText.setStyle(sf::Text::Bold);
//		pacmanText.setString("SASTA PAC-MAN ");
//		pacmanText.setPosition(520, 0);
//		window.draw(pacmanText);
//		///////////////////
//		//drawing wall
//		for (int i = 0; i < rows; i++)
//		{
//			for (int j = 0; j < cols; j++)
//			{
//				if (map[i][j] == 1)
//				{
//					spriteWall.setPosition(sf::Vector2f((j * cell) + wallxspc, (i * cell) + wallyspc));
//					window.draw(spriteWall);
//				}
//				if (map[i][j] == 0)
//				{
//					spriteSpace.setPosition(sf::Vector2f((j * cell) + wallxspc - 2, (i * cell) + wallyspc - 5));
//					window.draw(spriteSpace);
//				}
//			}
//		}
//		window.draw(scoreText);
//		window.draw(scoreVal);
//		window.draw(circ);
//
//		//drawing dots
//		for (int i = 0; i < rows; i++)
//		{
//			for (int j = 0; j < cols; j++)
//			{
//				if (map[i][j] == 2)
//				{
//					spriteDot.setPosition(sf::Vector2f((j * cell) + dotxspc, (i * cell) + dotyspc));
//					window.draw(spriteDot);
//				}
//				if (map[i][j] == 9)
//				{
//					spriteGate.setPosition(sf::Vector2f((j * cell) + dotxspc - 12, (i * cell) + dotyspc - 9));
//					window.draw(spriteGate);
//				}
//			}
//		}
//	
//		/*if (just_once_dummy == 0)
//		{
//			for (int i = 1; i <= 1000; i++)
//			{
//				window.draw(pacmanText);
//				if (i==100||i==200||i==300||i==400||1==500||i==600||i==700||i==800||i==900||i==1000)
//				{
//					window.clear();
//					Sleep(1);
//
//				}
//			}
//
//			
//			just_once_dummy = 1;
//		}*/
//
//		/////////////////////////////////
//		// //Moving
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
//		{
//			while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)))
//			{
//				if (map[pacx][pacy - 1] != 1 && map[pacx][pacy - 1] != 9)
//				{
//					for (int i = 0; i < 30; i++)
//					{
//						window.clear();
//						stringstream ss;
//						ss << score;
//
//						scoreVal.setString(ss.str());
//						window.draw(scoreText);
//						window.draw(scoreVal);
//
//						sf::Vector2f circPos = circ.getPosition();
//						if (circ.getGlobalBounds().left <= 0.0f)
//						{
//							circ.setPosition(0.0f, circPos.y);
//							break;
//						}
//						circ.move(-1.0f, 0.0f);
//
//
//						{
//							//drawing wall
//							for (int i = 0; i < rows; i++)
//							{
//								for (int j = 0; j < cols; j++)
//								{
//									if (map[i][j] == 1)
//									{
//										spriteWall.setPosition(sf::Vector2f((j * cell) + wallxspc, (i * cell) + wallyspc));
//										window.draw(spriteWall);
//									}
//									if (map[i][j] == 0)
//									{
//										spriteSpace.setPosition(sf::Vector2f((j * cell) + wallxspc - 2, (i * cell) + wallyspc - 5));
//										window.draw(spriteSpace);
//									}
//								}
//							}
//							window.draw(circ);
//							window.draw(pacmanText);
//
//							//drawing dots
//							for (int i = 0; i < rows; i++)
//							{
//								for (int j = 0; j < cols; j++)
//								{
//									if (map[i][j] == 2)
//									{
//										spriteDot.setPosition(sf::Vector2f((j * cell) + dotxspc, (i * cell) + dotyspc));
//										window.draw(spriteDot);
//									}
//									if (map[i][j] == 9)
//									{
//										spriteGate.setPosition(sf::Vector2f((j * cell) + dotxspc - 12, (i * cell) + dotyspc - 9));
//										window.draw(spriteGate);
//									}
//								}
//							}
//							window.draw(circ);
//							window.display();
//						}
//						if (i == 15)
//						{
//							if (map[pacx][pacy - 1] == 2)
//							{
//								score++;
//								soundChomp.play();
//
//							}
//							map[pacx][pacy - 1] = 0;
//
//						}
//
//
//					}
//					pacy--;
//					cout << "x=" << pacx << "  y=" << pacy << " , " << endl << " map " << map[pacx][pacy] << endl;
//				}
//
//			}
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
//		{
//			while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)))
//			{
//				if (map[pacx][pacy + 1] != 1 && map[pacx][pacy + 1] != 9)
//				{
//					for (int i = 0; i < 30; i++)
//					{
//						window.clear();
//
//						//updatescore(ss);
//						// 
//						//scoreVal.setString(ss.str());
//
//						//ss >> score;
//						stringstream ss;
//
//						ss << score;
//						scoreVal.setString(ss.str());
//						window.draw(scoreText);
//						window.draw(scoreVal);
//
//
//						sf::Vector2f circPos = circ.getPosition();
//						if (circ.getGlobalBounds().left + circ.getGlobalBounds().width >= window.getSize().x)
//						{
//							circ.setPosition((window.getSize().x - circ.getGlobalBounds().width), circPos.y);
//							break;
//						}
//						window.draw(pacmanText);
//
//						circ.move(1.0f, 0.0f);
//						{
//							//drawing wall
//							for (int i = 0; i < rows; i++)
//							{
//								for (int j = 0; j < cols; j++)
//								{
//									if (map[i][j] == 1)
//									{
//										spriteWall.setPosition(sf::Vector2f((j * cell) + wallxspc, (i * cell) + wallyspc));
//										window.draw(spriteWall);
//									}
//									if (map[i][j] == 0)
//									{
//										spriteSpace.setPosition(sf::Vector2f((j * cell) + wallxspc - 2, (i * cell) + wallyspc - 5));
//										window.draw(spriteSpace);
//									}
//								}
//							}
//							window.draw(circ);
//
//							//drawing dots
//							for (int i = 0; i < rows; i++)
//							{
//								for (int j = 0; j < cols; j++)
//								{
//									if (map[i][j] == 2)
//									{
//										spriteDot.setPosition(sf::Vector2f((j * cell) + dotxspc, (i * cell) + dotyspc));
//										window.draw(spriteDot);
//									}
//									if (map[i][j] == 9)
//									{
//										spriteGate.setPosition(sf::Vector2f((j * cell) + dotxspc - 12, (i * cell) + dotyspc - 9));
//										window.draw(spriteGate);
//									}
//								}
//							}
//						}
//						window.draw(circ);
//						window.display();
//
//						if (i == 15)
//						{
//							if (map[pacx][pacy + 1] == 2)
//							{
//								score++;
//								soundChomp.play();
//
//							}
//							map[pacx][pacy + 1] = 0;
//
//
//						}
//
//					}
//					pacy++;
//					cout << "x=" << pacx << "  y=" << pacy << " , " << endl << " map " << map[pacx][pacy] << endl;
//				}
//			}
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
//		{
//			while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)))
//			{
//				if (map[pacx - 1][pacy] != 1 && map[pacx - 1][pacy] != 9)
//				{
//					for (int i = 0; i < 30; i++)
//					{
//						window.clear();
//						stringstream ss;
//						ss << score;
//
//						scoreVal.setString(ss.str());
//
//						window.draw(scoreText);
//						window.draw(scoreVal);
//
//						sf::Vector2f circPos = circ.getPosition();
//						if (circ.getGlobalBounds().top <= 0.0f)
//						{
//							circ.setPosition(circPos.x, 0.0f);
//							break;
//						}
//						circ.move(0.0f, -1.0f);
//
//						{
//							//drawing wall
//							for (int i = 0; i < rows; i++)
//							{
//								for (int j = 0; j < cols; j++)
//								{
//									if (map[i][j] == 1)
//									{
//										spriteWall.setPosition(sf::Vector2f((j * cell) + wallxspc, (i * cell) + wallyspc));
//										window.draw(spriteWall);
//									}
//									if (map[i][j] == 0)
//									{
//										spriteSpace.setPosition(sf::Vector2f((j * cell) + wallxspc - 2, (i * cell) + wallyspc - 5));
//										window.draw(spriteSpace);
//									}
//								}
//							}
//							window.draw(circ);
//							window.draw(pacmanText);
//
//
//							//drawing dots
//							for (int i = 0; i < rows; i++)
//							{
//								for (int j = 0; j < cols; j++)
//								{
//									if (map[i][j] == 2)
//									{
//										spriteDot.setPosition(sf::Vector2f((j * cell) + dotxspc, (i * cell) + dotyspc));
//										window.draw(spriteDot);
//									}
//									if (map[i][j] == 9)
//									{
//										spriteGate.setPosition(sf::Vector2f((j * cell) + dotxspc - 12, (i * cell) + dotyspc - 9));
//										window.draw(spriteGate);
//									}
//								}
//							}
//						}
//						window.draw(circ);
//						window.display();
//
//						if (i == 15)
//						{
//							if (map[pacx - 1][pacy] == 2)
//							{
//								score++;
//								soundChomp.play();
//
//							}
//							map[pacx - 1][pacy] = 0;
//
//
//						}
//
//					}
//					pacx--;
//					cout << "x=" << pacx << "  y=" << pacy << " , " << endl << " map " << map[pacx][pacy] << endl;
//				}
//			}
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
//		{
//			while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)))
//			{
//				if (map[pacx + 1][pacy] != 1 && map[pacx + 1][pacy] != 9)
//				{
//					for (int i = 0; i < 30; i++)
//					{
//						window.clear();
//						stringstream ss;
//						ss << score;
//						scoreVal.setString(ss.str());
//						window.draw(scoreText);
//						window.draw(scoreVal);
//						sf::Vector2f circPos = circ.getPosition();
//						if (circ.getGlobalBounds().top + circ.getGlobalBounds().height >= window.getSize().y)
//						{
//							circ.setPosition(circPos.x, (window.getSize().y - circ.getGlobalBounds().height));
//							break;
//						}
//						window.draw(pacmanText);
//
//						circ.move(0.0f, 1.0f);
//						{
//							//drawing wall
//							for (int i = 0; i < rows; i++)
//							{
//								for (int j = 0; j < cols; j++)
//								{
//									if (map[i][j] == 1)
//									{
//										spriteWall.setPosition(sf::Vector2f((j * cell) + wallxspc, (i * cell) + wallyspc));
//										window.draw(spriteWall);
//									}
//									if (map[i][j] == 0)
//									{
//										spriteSpace.setPosition(sf::Vector2f((j * cell) + wallxspc - 2, (i * cell) + wallyspc - 5));
//										window.draw(spriteSpace);
//									}
//								}
//							}
//							window.draw(circ);
//
//							//drawing dots
//							for (int i = 0; i < rows; i++)
//							{
//								for (int j = 0; j < cols; j++)
//								{
//									if (map[i][j] == 2)
//									{
//										spriteDot.setPosition(sf::Vector2f((j * cell) + dotxspc, (i * cell) + dotyspc));
//										window.draw(spriteDot);
//									}
//									if (map[i][j] == 9)
//									{
//										spriteGate.setPosition(sf::Vector2f((j * cell) + dotxspc - 12, (i * cell) + dotyspc - 9));
//										window.draw(spriteGate);
//									}
//								}
//							}
//						}
//						window.draw(circ);
//						window.display();
//						if (i == 15)
//						{
//							if (map[pacx + 1][pacy] == 2)
//							{
//								score++;
//								soundChomp.play();
//							}
//							map[pacx + 1][pacy] = 0;
//						}
//					}
//					pacx++;
//					cout << "x=" << pacx << "  y=" << pacy << " , " << endl << " map " << map[pacx][pacy] << endl;
//				}
//			}
//		}
//		window.draw(scoreText);
//		window.draw(scoreVal);
//		window.display();
//	}
//}