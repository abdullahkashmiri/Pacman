//#include<SFML/Graphics.hpp>
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
//	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
//	player.setPosition(206.0f, 206.0f);
//	sf::Texture playerTexture;
//	playerTexture.loadFromFile("pacmanimggg.jpg");
//	player.setTexture(&playerTexture);
//
//	
//
//	while (window.isOpen())
//	{
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
//			window.clear();
//			window.draw(player);
//			window.display();
//		}
//	}
//	return 0;
//}