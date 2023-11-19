#include "Enemy.h"
#include <iostream>

Enemy::Enemy() {
    isAlive = true;
    health = 70.0f;
    setPosition({ 30.0f, 30.0f });
}

Enemy::Enemy(sf::Vector2f pos_, sf::Texture* texture) : Entity(*texture, pos_) {
    isAlive = true;
    health = 70.0f;
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