///////////////////////////////////////////////////////////////////////////////
// 
// Author:           SFML (Code), HerbGlitch (Installation Instructions),
//                   Caleb Sneath (Banner)
// Email:            ansengor@yahoo.com, terry.griffin@msutexas.edu
// Label:            A06
// Title:            SFML Intro
// Course:           CMPS 2143
// Semester:         Spring 2021
//
// Description:
//       This program prints a green ball
///////////////////////////////////////////////////////////////////////////////

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
