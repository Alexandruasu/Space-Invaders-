#include "Enemy.h"
#include <iostream>

Enemy::Enemy() : Entity() {
    isAlive = true;
    health = 30.0f;
    setPosition({ 30.0f, 30.0f });
}

Enemy::Enemy(const Enemy& other) : Entity(other) {
    isAlive = other.isAlive;
    health = other.health;
}

std::ostream& operator<<(std::ostream& out, const Enemy& enemy) {
    out << "Health: " << enemy.health << "\n";
    return out;
}

void Enemy::die() {
    isAlive = false;
}

void Enemy::takeDamage(float damage) {
    health -= damage;
    if (health <= 0) {
        die();
    }
}