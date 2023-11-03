#pragma once

#include "../Enemy/Enemy.h"

#ifndef OOP_ENEMYROW_H
#define OOP_ENEMYROW_H


class EnemyRow {
private:
    Enemy enemies[5];
    int xPos{};
    int yPos{};
public:
    EnemyRow();
    explicit EnemyRow(float y);
    friend std::ostream& operator<<(std::ostream& out, const EnemyRow& enemyRow);
    Enemy* getEnemies() { return &enemies[0]; }
    int getEnemyCount() const { return 5; }
    void killEnemy(int j);
};


#endif //OOP_ENEMYROW_H
