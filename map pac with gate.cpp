//#include<iostream>
//#include<SFML/Graphics.hpp>
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
//
//
//
//int main()
//{
//
//	sf::RenderWindow window(sf::VideoMode(1280, 1000), "SASTA PAC-MAN");
//	window.setFramerateLimit(60);
//
//	sf::Texture wall;
//	if (!wall.loadFromFile("res/wall.png"))
//	{
//		cout << "Load failed " << endl;
//		system("pause");
//	}
//	sf::Texture dot;
//	if (!dot.loadFromFile("res/dot.jpg"))
//	{
//		cout << "Load failed " << endl;
//		system("pause");
//	}
//	sf::Texture gate;
//	if (!gate.loadFromFile("res/dot.jpg"))
//	{
//		cout << "Load failed " << endl;
//		system("pause");
//	}
//
//	int map[rows][cols] = {
//		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//1
//		{1,2,2,2,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,2,2,2,1},//2
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
//
//		window.draw(circ);
//
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
//			}
//		}
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
//
//				if (map[i][j] == 9)
//				{
//					spriteGate.setPosition(sf::Vector2f((j * cell) + dotxspc-12, (i * cell) + dotyspc-9));
//					window.draw(spriteGate);
//				}
//			}
//		}
//		/////////////////////////////////
//		// //Moving
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
//		{
//			while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)))
//			{
//				if (map[pacx][pacy-1] != 1 && map[pacx][pacy - 1] != 9 )
//				{
//					for (int i = 0; i < 30; i++)
//					{
//						window.clear();
//						sf::Vector2f circPos = circ.getPosition();
//						if (circ.getGlobalBounds().left <= 0.0f)
//						{
//							circ.setPosition(0.0f, circPos.y);
//							break;
//						}
//						circ.move(-1.0f, 0.0f);
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
//								}
//							}
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
//									
//									if (map[i][j] == 9)
//									{
//										spriteGate.setPosition(sf::Vector2f((j * cell) + dotxspc - 12, (i * cell) + dotyspc - 9));
//										window.draw(spriteGate);
//									}
//
//								}
//							}
//							//window.draw(spriteWall);
//							//window.draw(spriteDot);
//							window.draw(circ);
//							window.display();
//						}
//					}
//					pacy--;
//					//cout << pacx;
//					//pacy;
//				cout << "x=" << pacx << "  y=" << pacy << " , "<< endl << " map " << map[pacx][pacy] << endl;
//
//				}
//				
//			}
//		}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
//			{
//				while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)))
//				{
//					if (map[pacx ][pacy+1] != 1 && map[pacx][pacy + 1] != 9 )
//					{
//						for (int i = 0; i < 30; i++)
//						{
//							window.clear();
//							sf::Vector2f circPos = circ.getPosition();
//							if (circ.getGlobalBounds().left + circ.getGlobalBounds().width >= window.getSize().x)
//							{
//								circ.setPosition((window.getSize().x - circ.getGlobalBounds().width), circPos.y);
//								break;
//							}
//							circ.move(1.0f, 0.0f);
//
//							{
//								//drawing wall
//								for (int i = 0; i < rows; i++)
//								{
//									for (int j = 0; j < cols; j++)
//									{
//										if (map[i][j] == 1)
//										{
//											spriteWall.setPosition(sf::Vector2f((j * cell) + wallxspc, (i * cell) + wallyspc));
//											window.draw(spriteWall);
//										}
//									}
//								}
//								//drawing dots
//								for (int i = 0; i < rows; i++)
//								{
//									for (int j = 0; j < cols; j++)
//									{
//										if (map[i][j] == 2)
//										{
//											spriteDot.setPosition(sf::Vector2f((j * cell) + dotxspc, (i * cell) + dotyspc));
//											window.draw(spriteDot);
//										}
//
//										if (map[i][j] == 9)
//										{
//											spriteGate.setPosition(sf::Vector2f((j * cell) + dotxspc - 12, (i * cell) + dotyspc - 9));
//											window.draw(spriteGate);
//										}
//									}
//								}
//							}
//							window.draw(circ);
//							window.display();
//						}
//
//						pacy++;
//					//	cout << pacx;
//						cout << "x=" << pacx << "  y=" << pacy << " , " << endl << " map " << map[pacx][pacy] << endl;
//
//					}
//
//				}
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
//			{
//				while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)))
//				{
//					if (map[pacx-1][pacy] != 1  && map[pacx - 1][pacy] != 9 )
//					{
//						for (int i = 0; i < 30; i++)
//						{
//							window.clear();
//							sf::Vector2f circPos = circ.getPosition();
//							if (circ.getGlobalBounds().top <= 0.0f)
//							{
//								circ.setPosition(circPos.x, 0.0f);
//								break;
//							}
//							circ.move(0.0f, -1.0f);
//							{
//								//drawing wall
//								for (int i = 0; i < rows; i++)
//								{
//									for (int j = 0; j < cols; j++)
//									{
//										if (map[i][j] == 1)
//										{
//											spriteWall.setPosition(sf::Vector2f((j * cell) + wallxspc, (i * cell) + wallyspc));
//											window.draw(spriteWall);
//										}
//									}
//								}
//								//drawing dots
//								for (int i = 0; i < rows; i++)
//								{
//									for (int j = 0; j < cols; j++)
//									{
//										if (map[i][j] == 2)
//										{
//											spriteDot.setPosition(sf::Vector2f((j * cell) + dotxspc, (i * cell) + dotyspc));
//											window.draw(spriteDot);
//										}
//										if (map[i][j] == 9)
//										{
//											spriteGate.setPosition(sf::Vector2f((j * cell) + dotxspc - 12, (i * cell) + dotyspc - 9));
//											window.draw(spriteGate);
//										}
//									}
//								}
//							}
//
//							window.draw(circ);
//							window.display();
//						}
//						pacx--;
//					//	cout << pacy;
//						cout << "x=" << pacx << "  y=" << pacy << " , " << endl << " map " << map[pacx][pacy] << endl;
//
//					}
//				}
//			}
//
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
//			{
//				while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)))
//				{
//					if (map[pacx+1][pacy] != 1 && map[pacx + 1][pacy] != 9)
//					{
//						for (int i = 0; i < 30; i++)
//						{
//							window.clear();
//							sf::Vector2f circPos = circ.getPosition();
//							if (circ.getGlobalBounds().top + circ.getGlobalBounds().height >= window.getSize().y)
//							{
//								circ.setPosition(circPos.x, (window.getSize().y - circ.getGlobalBounds().height));
//								break;
//							}
//							circ.move(0.0f, 1.0f);
//
//							{
//								//drawing wall
//								for (int i = 0; i < rows; i++)
//								{
//									for (int j = 0; j < cols; j++)
//									{
//										if (map[i][j] == 1)
//										{
//											spriteWall.setPosition(sf::Vector2f((j * cell) + wallxspc, (i * cell) + wallyspc));
//											window.draw(spriteWall);
//										}
//									}
//								}
//								//drawing dots
//								for (int i = 0; i < rows; i++)
//								{
//									for (int j = 0; j < cols; j++)
//									{
//										if (map[i][j] == 2)
//										{
//											spriteDot.setPosition(sf::Vector2f((j * cell) + dotxspc, (i * cell) + dotyspc));
//											window.draw(spriteDot);
//										}
//										if (map[i][j] == 9)
//										{
//											spriteGate.setPosition(sf::Vector2f((j * cell) + dotxspc - 12, (i * cell) + dotyspc - 9));
//											window.draw(spriteGate);
//										}
//									}
//
//								}
//							}
//							window.draw(circ);
//							window.display();
//						}
//				//		cout << pacy;
//						pacx++;
//						cout << "x=" << pacx << "  y=" << pacy << " , " << endl << " map " << map[pacx][pacy] << endl;
//
//					}
//
//				}
//			}
//			/////////////////////////////////
//
//
//
//
//			window.display();
//		
//	}
//}