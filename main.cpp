#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>

#include "Player/Player.h"
#include "EnemyRow/EnemyRow.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif

int main() {
#ifdef __linux__
    XInitThreads();
#endif

    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 600), "Space Invaders", sf::Style::Default);
    // window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    Player player = Player();
    EnemyRow enemyRow1 = EnemyRow(20.0f);

    while(window.isOpen()) {
        sf::Event e = sf::Event();
        while(window.pollEvent(e)) {
            switch(e.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    std::cout << "New width: " << window.getSize().x << '\n'
                              << "New height: " << window.getSize().y << '\n';
                    break;
                case sf::Event::KeyPressed:
                    std::cout << "Received key " << (e.key.code == sf::Keyboard::X ? "X" : "(other)") << "\n";
                    break;
                default:
                    break;
            }
        }

        window.clear(sf::Color::Black);

        int enemiesCount = 5;
        Enemy** enemies = enemyRow1.getEnemies();

        player.loop(enemies, enemiesCount, enemyRow1);

        window.draw(player.getSprite());
        for (int i = 0; i < enemiesCount; i++) {
            window.draw(enemies[i]->getSprite());
        }

        Bullet* bullets = player.getBullets();
        for (int i = 0; i < player.getBulletCount(); i++) {
            window.draw(bullets[i].getSprite());
        }

        window.display();
    }

    return 0;
}