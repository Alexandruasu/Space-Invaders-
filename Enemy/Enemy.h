#pragma once

#include "../Entity/Entity.h"
#include <SFML/Graphics.hpp>

#ifndef OOP_ENEMY_H
#define OOP_ENEMY_H


class Enemy : public Entity {
private:
    float health;
    bool isAlive;
public:
    Enemy();
    explicit Enemy(sf::Vector2f pos_, sf::Texture* texture);
    Enemy(const Enemy& other);
    friend std::ostream& operator<<(std::ostream& out, const Enemy& enemy);
    float getHealth() const { return health; }
    bool getIsAlive() const { return isAlive; }
    void setHealth(float hp) { health = hp; }
    void die();
};


#endif //OOP_ENEMY_H
