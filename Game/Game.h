#include "../Player/Player.h"

#include <iostream>

#ifndef OOP_GAME_H
#define OOP_GAME_H


class Game {
private:
    std::vector<Entity*> entities;
    Player *player;
    std::map<std::string, sf::Texture> textures;
    std::vector<float> rowsHeights;
    std::vector<Enemy*> enemies;
    sf::RenderWindow window;
    static int currentLevel;
public:
    Game();
    Game(const Game& game_) = delete;
    Game& operator=(const Game& game_) = delete;
    void createEnemyRow(int num);
    void run();
    static void increaseLevel();
};


#endif //OOP_GAME_H
