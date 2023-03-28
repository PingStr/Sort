#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <random>

struct bar
{
    int h;
    float x, y;
};
int main()
{
    // Create the main window
    int op = 2;
    float wdt = 900;
    float hgt = 500;
    int nb = 200;
    if (op == 1)
    {
        std::cout<<"Introduceti latimea, inaltimea si numarul de bare: \n";
        std::cin>>wdt>>hgt>>nb;
    }
    float mbarh = 0.9 * hgt;
    float barw = wdt / nb;
    bar lungs[nb + 2];
    srand(time(NULL));
    for (int i = 0; i < nb; i ++)
    {
        lungs[i].h = rand() % (int)mbarh;
        lungs[i].x = i * barw;
        lungs[i].y = hgt - lungs[i].h;
    }

    // Deschide fereastra

    sf::RenderWindow app(sf::VideoMode(wdt, hgt), "SFML window");
    sf::RectangleShape rectang;
    bool ok = 0;
    int cnt = 0;
    int itt = 0;
	// Evenimente
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        // Clear screen
        app.clear();

        int i = itt, j = cnt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if(lungs[i].h > lungs[j].h)
            {
                std::swap(lungs[i].h, lungs[j].h);
                std::swap(lungs[i].y, lungs[j].y);
                ok = 1;
            }
            cnt++;
            if (cnt > nb)
            {
                if(itt < nb - 1)
                    ++itt;
                cnt = itt + 1;
                ok = 0;
            }
        }

        // Deseneaza
        for (int k = 0; k < nb; k ++)
        {
            rectang.setSize(sf::Vector2f(barw, lungs[k].h));
            if (k == cnt && ok == 1)
                rectang.setFillColor(sf::Color::Red);
            else
                rectang.setFillColor(sf::Color::Yellow);
            rectang.setPosition(lungs[k].x, lungs[k].y);
            app.draw(rectang);
        }
        // Update the window
        app.display();
    }

    return 0;
}
