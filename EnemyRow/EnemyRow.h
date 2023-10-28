#pragma once

#include "../Enemy/Enemy.h"

#ifndef OOP_ENEMYROW_H
#define OOP_ENEMYROW_H


class EnemyRow {
private:
    Enemy* enemies[5];
    int xPos;
    int yPos;
public:
    EnemyRow();
    EnemyRow(float y);
    Enemy** getEnemies() { return &enemies[0]; }
    void killEnemy(int j);
};


#endif //OOP_ENEMYROW_H
