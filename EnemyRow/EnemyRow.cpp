
#include "EnemyRow.h"

EnemyRow::EnemyRow() {
    xPos = 0.0f;
    yPos = 0.0f;
}

EnemyRow::EnemyRow(float y) {
    xPos = 10.0f;
    yPos = (int)y;
    float offset = (float)(800 - 20) / 5;
    for (auto & enemie : enemies) {
        enemie = Enemy((float)xPos, (float)yPos);
        xPos += (int)offset;
    }
}

std::ostream& operator<<(std::ostream& out, const EnemyRow& enemyRow) {
    out << "xPos: " << enemyRow.xPos << "| yPos: " << enemyRow.yPos << '\n';
    return out;
}