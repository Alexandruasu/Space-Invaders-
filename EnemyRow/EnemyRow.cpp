
#include "EnemyRow.h"

EnemyRow::EnemyRow() : pos({0.0f, 0.0f}) {
    enemies = std::array<Enemy, 5>();
}

EnemyRow::EnemyRow(float y) : pos({ 10.0f, y }) {
    enemies = std::array<Enemy, 5>();
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