
#include "EnemyRow.h"
#include <iostream>

EnemyRow::EnemyRow() : enemies({}), pos({0.0f, 0.0f}) {
    std::cout << "enemy row constructor\n";
}

EnemyRow::EnemyRow(float y) : enemies({}), pos({ 10.0f, y }) {
    float offset = (800.0f - 20.0f) / 5.0f;
    for (auto & enemy : enemies) {
        enemy = Enemy(pos);
        pos.x += offset;
    }
}

std::ostream& operator<<(std::ostream& out, const EnemyRow& enemyRow) {
    out << "xPos: " << enemyRow.pos.x << "| yPos: " << enemyRow.pos.y << '\n';
    return out;
}