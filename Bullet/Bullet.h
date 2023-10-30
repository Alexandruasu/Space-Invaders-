#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet {
private:
    float damage;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Sprite sprite;
    sf::Texture* texture;
public:
    explicit Bullet(sf::Vector2f position_);
    friend std::ostream& operator<<(std::ostream& os, const Bullet& bullet);
    sf::Sprite getSprite() { return sprite; }
    void update();
    bool checkCollision();
    float getDamage() { return damage; }
};