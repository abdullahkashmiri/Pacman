//#include<SFML/Graphics.hpp>
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(1280, 720), "SASTA PACMAN XP");
//	window.setFramerateLimit(60);
//
//	sf::CircleShape circ;
//	sf::Vector2f circlePosition(600, 350);
//	circ.setPosition(circlePosition);
//	circ.setRadius(50);
//	circ.setFillColor(sf::Color::Yellow);
//
//	
//	sf::RectangleShape rect(sf::Vector2f(20.0f, 20.0f));
//	rect.setFillColor(sf::Color::Blue);
//
//
//	
//	const int rows =21;
//	const int cols = 21;
//	
//
//	int App[rows][cols] = { 0 };
//	for (int i =2 ; i < rows-7; i++)
//	{
//		App[i][5] = 1;
//	}
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//				window.close();
//		}
//
//
//		// Maze  
//		for (int i = 0; i < rows; i+=10)
//		{
//			for (int j = 0; j < cols; j++)
//			{
//				if (App[i][j] == 1)
//				{
//					window.clear();
//					window.draw(rect);
//					window.display();
//
//				}
//			}
//		}
//
//
//		//Moving
//		
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
//		{
//			while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)))
//			{
//				sf::Vector2f circPos = circ.getPosition();
//				if (circ.getGlobalBounds().left <= 0.0f)
//				{
//					circ.setPosition(0.0f, circPos.y);
//					break;
//				}
//				circ.move(-4.0f, 0.0f);
//				window.clear();
//				window.draw(circ);
//				window.display();
//			}
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
//		{
//			while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)))
//			{
//				sf::Vector2f circPos = circ.getPosition();
//				if (circ.getGlobalBounds().left + circ.getGlobalBounds().width >= window.getSize().x)
//				{
//					circ.setPosition((window.getSize().x - circ.getGlobalBounds().width), circPos.y);
//					break;
//				}
//				circ.move(4.0f, 0.0f);
//				window.clear();
//				window.draw(circ);
//				window.display();
//			}
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
//		{
//			while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)))
//			{
//				sf::Vector2f circPos = circ.getPosition();
//				if (circ.getGlobalBounds().top <= 0.0f)
//				{
//					circ.setPosition(circPos.x, 0.0f);
//					break;
//				}
//				circ.move(0.0f, -4.0f);
//				window.clear();
//				window.draw(circ);
//				window.display();
//			}
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
//		{
//			while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)))
//			{
//				sf::Vector2f circPos = circ.getPosition();
//				if (circ.getGlobalBounds().top + circ.getGlobalBounds().height >= window.getSize().y)
//				{
//					circ.setPosition(circPos.x, (window.getSize().y - circ.getGlobalBounds().height));
//					break;
//				}
//				circ.move(0.0f, 4.0f);
//				window.clear();
//				window.draw(circ);
//				window.display();
//			}
//		}
//		//render
//		window.clear();
//		window.draw(circ);
//		window.display();
//
//	}
//
//
//
//
//	return 0;
//
//}