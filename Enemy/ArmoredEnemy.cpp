#include "Enemy.h"

ArmoredEnemy::ArmoredEnemy() : Enemy() { }

void ArmoredEnemy::die() {
    std::cout << "Armored enemy died" << std::endl;
    Enemy::die();
}

void ArmoredEnemy::takeDamage(float damage) {
    Enemy::takeDamage(damage / 5.0f);
}