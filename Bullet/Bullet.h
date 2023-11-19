#pragma once

#include "../Entity/Entity.h"
#include <iostream>

class Bullet : public Entity {
private:
    float damage;
public:
    explicit Bullet(sf::Vector2f position_, sf::Texture *texture_);
    friend std::ostream& operator<<(std::ostream& os, const Bullet& bullet);

    bool checkCollision();
    float getDamage() const { return damage; }

    Bullet();
    ~Bullet() override;
    Bullet(const Bullet& obj);
    Bullet &operator=(const Bullet &obj);
};