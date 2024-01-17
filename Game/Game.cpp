#include "Game.h"
#include "../Exceptions/Exceptions.h"
#include <iostream>

const std::string PLAYER_TEXTURE = "./Assets/Textures/Player.png";
const std::string ENEMY_TEXTURE = "./Assets/Textures/StandingEnemy.png";
const std::string MOVING_ENEMY_TEXTURE = "./Assets/Textures/MovingEnemy.png";
const std::string ARMORED_ENEMY_TEXTURE = "./Assets/Textures/ArmoredEnemy.png";
const std::string BULLET_TEXTURE = "./Assets/Textures/Bullet.png";

int Game::currentLevel = 1;

void Game::increaseLevel() {
    Game::currentLevel++;
}

void Game::end() {
    entities.erase(std::remove(entities.begin(), entities.end(), player), entities.end());
    delete player;
    for (Entity* entity : entities) {
        delete entity;
    }
    std::cout << "Game ended" << std::endl;
}

std::string Game::readLineFromFile(int lineNumber) {
    std::ifstream file("levels.txt");
    std::string line;

    for (int i = 0; i < lineNumber; i++) {
        if (!std::getline(file, line)) {
            return "";
        }
    }

    return line;
}

Game::Game() {
    window.create(sf::VideoMode(800, 600), "Space Invaders", sf::Style::Default);
    window.setFramerateLimit(60);
    textures = std::map<std::string, sf::Texture>();

    sf::Texture playerTexture = sf::Texture();
    playerTexture.loadFromFile(PLAYER_TEXTURE);

    sf::Texture standingEnemyTexture = sf::Texture();
    standingEnemyTexture.loadFromFile(ENEMY_TEXTURE);

    sf::Texture movingEnemyTexture = sf::Texture();
    movingEnemyTexture.loadFromFile(MOVING_ENEMY_TEXTURE);

    sf::Texture armoredEnemyTexture = sf::Texture();
    armoredEnemyTexture.loadFromFile(ARMORED_ENEMY_TEXTURE);

    sf::Texture bulletTexture = sf::Texture();
    bulletTexture.loadFromFile(BULLET_TEXTURE);

    textures["player"] = playerTexture;
    textures["standingEnemy"] = standingEnemyTexture;
    textures["movingEnemy"] = movingEnemyTexture;
    textures["armoredEnemy"] = armoredEnemyTexture;
    textures["bullet"] = bulletTexture;

    player = new Player(&textures["player"]);
    player->setBulletTexture(textures["bullet"]);
    player->setIsAlive(true);
    entities.push_back(player);

    rowsHeights = std::vector<float>();

    createEnemyRow("S");
}

void Game::createEnemyRow(const std::string& line) {
    int num = (int)line.length();
    std::cout << "Creating row of " << num << " enemies" << std::endl;
    float y = 20.0f;
    if (!rowsHeights.empty()) {
        auto rows = (float)rowsHeights.size();
        y += 120.0f * rows;
    }
    float offset = 800.0f / (float)num;
    float x = (offset / 2.0f) - 64.0f;
    for (int i = 0; i < num; i++) {
        Enemy* enemy;
        char enemyType = line[i];
        std::cout << enemyType << std::endl;
        switch (enemyType) {
            case 'A':
                std::cout << "Creating armored enemy" << std::endl;
                enemy = new ArmoredEnemy({x + ((float)i * offset), y}, &textures["armoredEnemy"]);
                break;
            case 'S':
                std::cout << "Creating standing enemy" << std::endl;
                enemy = new StandingEnemy({x + ((float)i * offset), y}, &textures["standingEnemy"]);
                break;
            case 'M':
                std::cout << "Creating moving enemy" << std::endl;
                enemy = new MovingEnemy({x + ((float)i * offset), y}, &textures["movingEnemy"]);
                break;
            default:
                std::cout << "Invalid enemy type: " << enemyType << std::endl;
                throw InvalidGameStateException();
        }
        enemies.push_back(enemy);
        // entities.push_back(enemy);
        entities.push_back(enemy);
    }
    rowsHeights.push_back(y);
}

void Game::run() {
    while (true) {
        while(window.isOpen()) {
            if (enemies.empty()) {
                Game::increaseLevel();
                break;
            }

            sf::Event e = sf::Event();
            while(window.pollEvent(e)) {
                switch(e.type) {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    default:
                        break;
                }
            }

            window.clear(sf::Color::Black);

            for (Entity* entity : entities) {
                entity->update();

                if (entity->getIsAlive()) {
                    entity->draw(window);

                    auto* player_ = dynamic_cast<Player*>(entity);
                    if (player_ != nullptr) {
                        player_->loop(enemies);
                        player_->drawBullets(window);
                        continue;
                    }

                    auto* enemy = dynamic_cast<Enemy*>(entity);
                    if (enemy != nullptr) {
                        // enemy code here...
                    }
                }
            }

            window.display();
        }

        if (enemies.empty()) {
            enemies = std::vector<Enemy*>();
            rowsHeights = std::vector<float>();

            std::string line = readLineFromFile(Game::currentLevel);

            std::cout << "Level " << Game::currentLevel << std::endl;
            std::cout << "Line: " << line << std::endl;

            if (line.empty()) {
                std::cout << "Game ended" << std::endl;
                throw InvalidGameStateException();
            }

            std::istringstream iss(line);
            char enemyType;
            std::string enemyTypes;
            while (iss >> enemyType) {
                std::cout << "Enemy type: " << enemyType << std::endl;
                if (enemyType == 'X') {
                    createEnemyRow(enemyTypes);
                    enemyTypes = "";
                    continue;
                }
                enemyTypes += enemyType;
                std::cout << "Enemy types: " << enemyTypes << std::endl;
            }
        }
    }
}