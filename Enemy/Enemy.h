#pragma once

#include <SFML/Graphics.hpp>

#ifndef OOP_ENEMY_H
#define OOP_ENEMY_H


class Enemy {
private:
    float health;
    sf::Sprite sprite;
    sf::Texture texture;
    bool isAlive;
public:
    Enemy();
    Enemy(float x, float y);
    friend std::ostream& operator<<(std::ostream& out, const Enemy& enemy);
    void setTexture(const sf::Texture& texture_);
    sf::Sprite getSprite() { return sprite; }
    float getHealth() const { return health; }
    void setHealth(float hp) { health = hp; }
    void die();
};


#endif //OOP_ENEMY_H
