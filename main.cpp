//#include<SFML/Graphics.hpp>
//#include "Animation.h"
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
//	sf::RectangleShape player(sf::Vector2f(95.0f, 63.0f));
//	player.setPosition(20.0f, 20.0f);
//	sf::Texture playerTexture;
//	playerTexture.loadFromFile("pacman16.png");
//	player.setTexture(&playerTexture);
//
//	Animation animation(&playerTexture, sf::Vector2u(95, 63), 0.3f);
//
//	float deltaTime = 0.0f;
//	sf::Clock clock;
//
//	
//	while (window.isOpen())
//	{
//		deltaTime=clock.restart().asSeconds();
//
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			switch (event.type)
//			{
//			case sf::Event::Closed:
//				window.close();
//				break;
//			}
//
//			animation.Update(0,deltaTime);
//			player.setTextureRect(animation.uvRect);
//
//
//			window.clear();
//			window.draw(player);
//			window.display();
//		}
//	}
//	return 0;
//}