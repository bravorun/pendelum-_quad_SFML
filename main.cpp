
#include <iostream>
#include <string>
#include <vector>

#include "Pendulum.h"

#define PI 3.14159265
#define LOG(x) std::cout << x << std::endl

int main()
{
    
    std::cout << "Ranjan " << std::endl;
    sf::ContextSettings settings;
    settings.antialiasingLevel =12;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Double Pendulum", sf::Style::Default, settings);
    sf::Event event;

    Pendulum p1(100, 90, 220, window.getSize().x / 2, 175);
    Pendulum p2(100, 90, 220, &p1);
    Pendulum p3(100, 90, 220, &p2);
    Pendulum p4(100, 90, 220, &p3);

    //You could add more pendulums but I am not sure if this is correct in terms of physics...
    //Pendulum p3(100, 90, 220, &p2);

    sf::Clock clock;
   // sf::Font font;

   /* if (!font.loadFromFile("OpenSans-Regular.ttf"))
    {
        LOG("Could not load font file..");
        return 1;
    }*/
    sf::Text text;
    //text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);

    std::vector<sf::Vertex> line;
    sf::Vertex* lineArr;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
            p4.update();
            line.push_back(sf::Vertex(p4.updatePos(clock.getElapsedTime().asSeconds() * 10), sf::Color::Blue));

            p3.update();
            line.push_back(sf::Vertex(p3.updatePos(clock.getElapsedTime().asSeconds() * 10), sf::Color::Red));
            p2.update();

            line.push_back(sf::Vertex(p2.updatePos(clock.getElapsedTime().asSeconds() * 10), sf::Color::Yellow));
            p1.updatePos(clock.getElapsedTime().asSeconds() * 5);
           
            clock.restart();
            lineArr = &line[0];
            window.clear(sf::Color::Black);

            window.draw(lineArr, line.size(), sf::Lines);
            p1.draw(window);
            p2.draw(window);
            p3.draw(window);
            p4.draw(window);

            window.display();
        
    }

    return 0;
}