//#include<SFML/Graphics.hpp>
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
//	sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f));
//	player.setPosition(206.0f, 206.0f);
//	sf::Texture playerTexture;
//	playerTexture.loadFromFile("pacmanimggg.jpg");
//	player.setTexture(&playerTexture);
//
//	sf::Vector2u textureSize =playerTexture.getSize();
//	textureSize.x /= 3;
//	textureSize.y /= 9;
//
//	player.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 2, textureSize.x, textureSize.y));
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