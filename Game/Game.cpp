#define PLAYER_TEXTURE "./Assets/Textures/Player.png"
#define ENEMY_TEXTURE "./Assets/Textures/Enemy.png"

#include "Game.h"

Game::Game() {
    window.create(sf::VideoMode(800, 600), "Space Invaders", sf::Style::Default);
    window.setFramerateLimit(60);
    textures = std::vector<sf::Texture>();

    sf::Texture playerTexture = sf::Texture();
    playerTexture.loadFromFile(PLAYER_TEXTURE);

    sf::Texture enemyTexture = sf::Texture();
    enemyTexture.loadFromFile(ENEMY_TEXTURE);

    textures.push_back(playerTexture);
    textures.push_back(enemyTexture);

    player = Player();
    player.setTexture(textures[0]);

    EnemyRow enemyRow1 = EnemyRow(20.0f);
    enemyRows.push_back(enemyRow1);
    Enemy* rowEnemies = enemyRows[0].getEnemies();
    for (int i = 0; i < enemyRows[0].getEnemyCount(); i++) {
        rowEnemies[i].setTexture(textures[1]);
        enemies.push_back(rowEnemies[i]);
    }
}

void Game::run() {
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

        player.loop(enemies.data(), (int)enemies.size());

        window.draw(player.getSprite());
        for (auto & enemy : enemies) {
            window.draw(enemy.getSprite());
        }

        Bullet* bullets = player.getBullets();
        for (int i = 0; i < player.getBulletCount(); i++) {
            window.draw(bullets[i].getSprite());
        }

        window.display();
    }
}