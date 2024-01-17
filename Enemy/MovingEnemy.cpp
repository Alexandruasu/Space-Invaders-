#include "Enemy.h"

MovingEnemy::MovingEnemy() : Enemy() {
    counter = 0;
}

void MovingEnemy::die() {
    std::cout << "Moving enemy died" << std::endl;
    Enemy::die();
}

void MovingEnemy::takeDamage(float damage) {
    Enemy::takeDamage(damage / 1.5f);
}

void MovingEnemy::update() {
    counter++;
    float direction = 1.0f;
    if (counter < 60) {
        direction = 1.0f;
    }
    else {
        direction = -1.0f;
    }

    setPosition(getPosition() + sf::Vector2f(1.0f * direction, 0.0f));

    if (counter == 120) {
        counter = 0;
    }
}