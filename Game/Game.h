#include "../Player/Player.h"

#include <iostream>

#ifndef OOP_GAME_H
#define OOP_GAME_H


class Game {
private:
    Player player{};
    std::vector<sf::Texture> textures{};
    std::vector<EnemyRow> enemyRows{};
    std::vector<Enemy> enemies{};
    sf::RenderWindow window{};
public:
    Game();
    void run();
};


#endif //OOP_GAME_H
