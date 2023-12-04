#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "../Bullet/Bullet.h"
#include "../Enemy/Enemy.h"

class Player : public Entity {
private:
    float health;
    float damage;
    float xSpeed;
    float ySpeed;
    int shootingCooldown;
    std::vector<Bullet*> bullets;
    sf::Texture *bulletTexture;
public:
    Player();
    explicit Player(sf::Texture* texture);
    ~Player();
    Player& operator=(const Player& other);
    Player(const Player& other);
    friend std::ostream& operator<<(std::ostream& out, const Player& player);
    void shoot();
    void setBulletTexture(sf::Texture& texture_);
    void handleShooting();
    void handleBulletsCollision(std::vector<Enemy*>& enemies);
    void handlePlayerCollision(std::vector<Enemy*>& enemies);
    void loop(std::vector<Enemy*>& enemies);
    void move();
    void drawBullets(sf::RenderWindow& window);
};