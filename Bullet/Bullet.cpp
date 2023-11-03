#include "Bullet.h"

#include <iostream>

Bullet::Bullet(sf::Vector2f position_) {
    std::cout << "Bullet constructor \n";
    damage = 10.0f;
    position = position_;
    velocity = sf::Vector2f(0.0f, -5.0f);
    texture = new sf::Texture();
    texture->loadFromFile("./Assets/Textures/Bullet.png");
    sprite.setTexture(*texture);
    sprite.setPosition(position);
}

std::ostream& operator<<(std::ostream& os, const Bullet& bullet) {
    os << "Bullet: \n"
       << "Damage: " << bullet.damage << '\n'
       << "Position: (" << bullet.position.x << ", " << bullet.position.y << ")\n"
       << "Velocity: (" << bullet.velocity.x << ", " << bullet.velocity.y << ")\n";
    return os;
}

void Bullet::update() {
    position += velocity;
    sprite.move(velocity);
}

bool Bullet::checkCollision() const {
    if (position.y < 0) {
        return true;
    }

    return false;
}
