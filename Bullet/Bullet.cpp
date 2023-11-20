#include "Bullet.h"

#include <iostream>

Bullet::Bullet(sf::Vector2f position_, sf::Texture *texture_) {
    std::cout << "Bullet constructor \n";
    damage = 10.0f;
    setTexture(texture_);
    setPosition(position_);
    setVelocity({ 0.0f, -5.0f });
}

std::ostream& operator<<(std::ostream& os, const Bullet& bullet) {
    os << "Bullet: \n"
       << "Damage: " << bullet.damage << '\n';
    return os;
}

Bullet::Bullet() {
    damage = 10.0f;
    
    setTexture(new sf::Texture());
    setPosition({0.0f, 0.0f});
    setVelocity({0.0f, -5.0f});
}

Bullet::Bullet(const Bullet& obj) : Entity(obj), damage(obj.damage) {
    std::cout << "operator copiere Bullet";
}

Bullet::~Bullet() {
    std::cout << "destructor Bullet";
}

Bullet& Bullet::operator=(const Bullet& obj) {
    if (&obj == this) {
        return *this;
    }
    damage = obj.damage;
    return *this;
}

bool Bullet::checkCollision() {
    if (getPosition().y < 0) {
        return true;
    }

    return false;
}
