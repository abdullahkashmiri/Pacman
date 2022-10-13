//#include<SFML/Graphics.hpp>
//
//int main()
//{
//
//	sf::RenderWindow window(sf::VideoMode(1280, 1000), "SASTA PAC-MAN");
//	window.setFramerateLimit(60);
//
//	sf::Texture pacmanimg;
//	pacmanimg.loadFromFile("pacman16.png");
//	sf::Sprite spritePacman(pacmanimg,sf::IntRect(0,0,95,63));
//	sf::Vector2u imagecount,currentImage;
//	float switchtime;
//	float totalTime;
//
//
//
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//		//handle all events
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//
//			totalTime = 0.0;
//			currentImage.x = 0;
//
//			uvRect.width = texture->getSize().x / float(imageCount.x);
//			uvRect.height = texture->getSize().y / float(imageCount.y);
//		}
//		void Animation::Update(int row, float deltaTime)
//		{
//			currentImage.y = row;
//			totalTime += deltaTime;
//
//			if (totalTime >= switchTime)
//			{
//				totalTime -= switchTime;
//				currentImage.x++;
//				if (currentImage.x >= imageCount.x)
//				{
//					currentImage.x = 0;
//				}
//			}
//
//
//			uvRect.left = currentImage.x * uvRect.width;
//			uvRect.top = currentImage.y * uvRect.height;
//
//
//
//
//
//
//		}
//
//
//		window.clear();
//		window.draw(spritePacman);
//		window.display();
//
//	}
//
//}
//
