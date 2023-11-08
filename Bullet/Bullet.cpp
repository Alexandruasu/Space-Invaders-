#include "Bullet.h"

#include <iostream>

Bullet::Bullet(sf::Vector2f position_) : position(position_), velocity({0.0f, -5.0f}) {
    std::cout << "Bullet constructor \n";
    damage = 10.0f;
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

Bullet::Bullet() : position({0.0f, 0.0f}), velocity({0.0f, -5.0f}) {
    damage = 10.0f;
    texture = new sf::Texture();
    texture->loadFromFile("./Assets/Textures/Bullet.png");
    sprite.setTexture(*texture);
    sprite.setPosition(position);
}

Bullet::Bullet(const Bullet& obj) : damage{obj.damage}, position{obj.position},velocity{obj.velocity}, sprite{obj.sprite}, texture{obj.texture} {
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
    position = obj.position;
    velocity = obj.velocity;
    sprite = sf::Sprite();
    texture = new sf::Texture();
    texture = obj.texture;
//    texture->loadFromFile("./Assets/Textures/Bullet.png");
    sprite.setTexture(*texture);
    sprite.setPosition(position);
    return *this;
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
