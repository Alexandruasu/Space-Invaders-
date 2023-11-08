#pragma once

#include "../Enemy/Enemy.h"
#include <array>

#ifndef OOP_ENEMYROW_H
#define OOP_ENEMYROW_H


class EnemyRow {
private:
    std::array<Enemy, 5> enemies;
    sf::Vector2f pos;
//    int xPos;
//    int yPos;
public:
    EnemyRow();
    explicit EnemyRow(float y);
    friend std::ostream& operator<<(std::ostream& out, const EnemyRow& enemyRow);
    Enemy* getEnemies() { return &enemies[0]; }
    int getEnemyCount() const { return 5; }
    void killEnemy(int j);
};


#endif //OOP_ENEMYROW_H
