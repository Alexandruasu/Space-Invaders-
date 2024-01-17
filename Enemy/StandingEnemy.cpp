#include "Enemy.h"

StandingEnemy::StandingEnemy() : Enemy() { }

void StandingEnemy::die() {
    std::cout << "Standing enemy died" << std::endl;
    Enemy::die();
}

void StandingEnemy::takeDamage(float damage) {
    Enemy::takeDamage(damage);
}