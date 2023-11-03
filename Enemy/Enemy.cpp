

#include "Enemy.h"
#include <iostream>

Enemy::Enemy() {
    isAlive = true;
    health = 70.0f;
    sprite.setPosition({ 30.0f, 30.0f });
}

Enemy::Enemy(float x, float y) {
    isAlive = true;
    health = 70.0f;
    texture.loadFromFile("./Assets/Textures/Enemy.png");
    sprite.setTexture(texture);
    sprite.setPosition({ x, y });
}

std::ostream& operator<<(std::ostream& out, const Enemy& enemy) {
    out << "Health: " << enemy.health << "\n";
    return out;
}

void Enemy::setTexture(const sf::Texture& texture_) {
    texture = texture_;
    sprite.setTexture(texture);
}

void Enemy::die() {
    sprite = sf::Sprite();
}