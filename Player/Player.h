#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "../Bullet/Bullet.h"
#include "../Enemy/Enemy.h"
#include "../EnemyRow/EnemyRow.h"

class Player {
private:
    float health;
    float damage;
    float xSpeed;
    float ySpeed;
    int shootingCooldown{};
    sf::Vector2f velocity;
    sf::Sprite sprite;
    sf::Texture texture;
    std::vector<Bullet> bullets;
public:
    Player();
    ~Player();
    Player& operator=(const Player& other);
    Player(const Player& other);
    friend std::ostream& operator<<(std::ostream& out, const Player& player);
    void shoot();
    void setTexture(const sf::Texture& texture_);
    void handleShooting();
    Bullet* getBullets() { return bullets.data(); }
    int getBulletCount() { return (int)bullets.size(); }
    void handleBulletsCollision(Enemy* enemies, int enemyCount);
    void loop(Enemy* enemies, int enemyCount);
    void move();

    sf::Sprite getSprite() { return sprite; }
};