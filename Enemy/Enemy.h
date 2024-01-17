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

    Enemy(sf::Vector2f pos_, sf::Texture* texture) : Entity(*texture, pos_) {
        isAlive = true;
        health = 30.0f;
    }
    
    Enemy(const Enemy& other);
    virtual ~Enemy() { std::cout << "Enemy destroyed" << std::endl; }

    friend std::ostream& operator<<(std::ostream& out, const Enemy& enemy);

    float getHealth() const { return health; }
    bool getIsAlive() const { return isAlive; }
    void setHealth(float hp) { health = hp; }
    virtual void die();
    virtual void takeDamage(float damage);
};

class StandingEnemy : public Enemy {
public:
    StandingEnemy();
    explicit StandingEnemy(sf::Vector2f pos_, sf::Texture* texture) : Enemy(pos_, texture) {}
    StandingEnemy(const StandingEnemy& other) : Enemy(other) {}
    ~StandingEnemy() override { std::cout << "Standing enemy destroyed" << std::endl; }

    void die() override;
    void takeDamage(float damage) override;
};

class MovingEnemy : public Enemy {
private:
    sf::Vector2f velocity;
    int counter = 0;
public:
    MovingEnemy();
    explicit MovingEnemy(sf::Vector2f pos_, sf::Texture* texture) : Enemy(pos_, texture) {}
    MovingEnemy(const MovingEnemy& other) : Enemy(other) {}
    ~MovingEnemy() override { std::cout << "Moving enemy destroyed" << std::endl; }

    void setVelocity(sf::Vector2f velocity_) { velocity = velocity_; }
    sf::Vector2f getVelocity() const { return velocity; }
    void update() override;
    void die() override;
    void takeDamage(float damage) override;
};

class ArmoredEnemy : public Enemy {
public:
    ArmoredEnemy();
    explicit ArmoredEnemy(sf::Vector2f pos_, sf::Texture* texture) : Enemy(pos_, texture) {}
    ArmoredEnemy(const ArmoredEnemy& other) : Enemy(other) {}
    ~ArmoredEnemy() override { std::cout << "Armored enemy destroyed" << std::endl; }

    void takeDamage(float damage) override;
    void die() override;
};

#endif //OOP_ENEMY_H
