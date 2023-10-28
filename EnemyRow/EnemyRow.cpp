
#include "EnemyRow.h"

EnemyRow::EnemyRow() {
    xPos = 0.0f;
    yPos = 0.0f;
}

EnemyRow::EnemyRow(float y) {
    xPos = 10.0f;
    yPos = y;
    float offset = (800 - 20) / 5;
    for (int i = 0; i < 5; i++) {
        enemies[i] = new Enemy(xPos, yPos);
        xPos += offset;
    }
}

void EnemyRow::killEnemy(int j) {
    enemies[j]->die();
}