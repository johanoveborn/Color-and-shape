#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape cshape(100.f);
    //shape.setFillColor(sf::Color::Green);

   // std::this_thread::sleep_for (std::chrono::seconds(10));
    sf::Color cColor;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        cColor.r = 0;
        cColor.g = 0;
        cColor.b = 0;
        cColor.a = 255;
        window.clear();
        std::this_thread::sleep_for (std::chrono::seconds(1));

        if (cColor.r < 1)
        {
            for(int colCountr = 0;colCountr < 256;colCountr++)
            {
                cColor.r += 1;
                cshape.setFillColor(cColor);
                window.clear();
                window.draw(cshape);
                window.display();
                std::this_thread::sleep_for (std::chrono::milliseconds(10));
            }
        }

         if (cColor.g < 1)
        {
            for(int colCountg = 0;colCountg < 256;colCountg++)
            {
                cColor.r = 255;
                cColor.g += 1;
                cshape.setFillColor(cColor);
                //cshape.getFillColor()
                window.clear();
                window.draw(cshape);
                window.display();
                std::this_thread::sleep_for (std::chrono::milliseconds(10));
            }
        }

         if (cColor.b < 1)
        {
            for(int colCountb = 0;colCountb < 256;colCountb++)
            {
                cColor.b += 1;
                cshape.setFillColor(cColor);
                window.clear();
                window.draw(cshape);
                window.display();
                std::this_thread::sleep_for (std::chrono::milliseconds(10));
            }
        }

    }

    return 0;
}
