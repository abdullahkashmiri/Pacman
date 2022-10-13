//#include<iostream>
//#include <SFML/Graphics.hpp>
//using namespace sf;
//
//int cell = 40;
//
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(1280, 720), "Pac-man");
//    sf::RectangleShape shape(Vector2f(30, 30));
//    shape.setFillColor(sf::Color::Black);
//    shape.setOutlineThickness(2.8);
//    shape.setOutlineColor(Color::Blue);
//    CircleShape dot(5);
//    dot.setFillColor(Color::Yellow);
//    CircleShape pac(15);
//    pac.setFillColor(Color::Yellow);
//    CircleShape eye(3);
//    eye.setFillColor(Color::Black);
//    CircleShape triangle(10, 3);
//    triangle.setFillColor(Color::Black);
//
//
//    window.setFramerateLimit(60);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        Vector2f position = shape.getPosition();
//        Vector2f pos = dot.getPosition();
//        Vector2f pos_pac = pac.getPosition();
//
//        char map_data[10][10] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },//1
//                               { 1, 3, 0, 0, 0, 0, 0, 0, 0, 1 },//2
//                               { 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },//3
//                               { 1, 0, 1, 0, 0, 0, 0, 1, 0, 1 },//4
//                               { 1, 0, 0, 2, 1, 1, 2, 0, 0, 1 },//5
//                               { 1, 0, 0, 2, 1, 1, 2, 0, 0, 1 },//6
//                               { 1, 0, 1, 0, 0, 0, 0, 1, 0, 1 },//7
//                               { 1, 0, 1, 1, 0, 1, 1, 1, 0, 1 },//8
//                               { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },//9
//                               { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };//10
//        //window.clear();
//        for (int i = 0; i < 10; i++)
//            for (int j = 0; j < 10; j++)
//            {
//                if (map_data[i][j] == 1)
//                {
//                    position.x = j * cell;
//                    position.y = i * cell;
//                    shape.setPosition(position.x, position.y);
//                    window.draw(shape);
//                }
//                else if (map_data[i][j] == 0)
//                {
//                    pos.x = j * cell + 12;
//                    pos.y = i * cell + 12;
//                    dot.setPosition(pos.x, pos.y);
//                    window.draw(dot);
//                }
//
//                else if (map_data[i][j] == 3)
//                {
//
//                    pos_pac.x = j * cell + 3;
//                    pos_pac.y = i * cell + 3;
//                    pac.setPosition(pos_pac.x, pos_pac.y);
//                    triangle.setPosition(pos_pac.x + 15, pos_pac.y + 5);
//                    triangle.setRotation(90);
//                    eye.setPosition(pos_pac.x + 7, pos_pac.y + 3);
//                    window.draw(pac);
//                    window.draw(eye);
//                    window.draw(triangle);
//                }
//
//            }
//        window.display();
//    }
//
//    return 0;
//}