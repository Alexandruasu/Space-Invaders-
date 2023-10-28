

#include "Enemy.h"

Enemy::Enemy() {
    health = 20.0f;
    texture.loadFromFile("./Assets/Textures/Enemy.png");
    sprite.setTexture(texture);
    sprite.setPosition({ 30.0f, 30.0f });
}

Enemy::Enemy(float x, float y) {
    health = 20.0f;
    texture.loadFromFile("./Assets/Textures/Enemy.png");
    sprite.setTexture(texture);
    sprite.setPosition({ x, y });
}

std::ostream& operator<<(std::ostream& out, const Enemy& enemy) {
    out << "Health: " << enemy.health << "\n";
    return out;
}

void Enemy::die() {
    sprite.setPosition({0.0f, -300.0f});
}