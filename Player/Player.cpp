#include "Player.h"
#include "../Exceptions/Exceptions.h"

#include <iostream>
#include <vector>

Player::Player() {
    std::cout << "Player default constructor \n";
    health = 100.0f;
    damage = 10.0f;
    xSpeed = 3.0f;
    ySpeed = 3.0f;
    shootingCooldown = 0;
    bulletTexture = new sf::Texture();
    setTexture(new sf::Texture());
    setVelocity({ 0.0f, 0.0f });
    setPosition({ 335.0f, 400.0f });
}

Player::Player(sf::Texture* texture) : bullets(std::vector<Bullet*>()) {
    std::cout << "Player constructor \n";
    health = 100.0f;
    damage = 10.0f;
    xSpeed = 3.0f;
    ySpeed = 3.0f;
    shootingCooldown = 0;
    bulletTexture = new sf::Texture();
    setTexture(texture);
    setVelocity({ 0.0f, 0.0f });
    setPosition({ 335.0f, 400.0f });
}

Player::~Player() {
    std::cout << "Player destructor \n";
}

Player& Player::operator=(const Player& other) {
    std::cout << "Player assignment operator \n";

    if (this == &other) {
        health = other.health;
        damage = other.damage;
        xSpeed = other.xSpeed;
        ySpeed = other.ySpeed;
        shootingCooldown = other.shootingCooldown;
        bulletTexture = other.bulletTexture;
    }

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Player& player) {
    out << "Health: " << player.health << "\n Damage: " << player.damage << "\n";
    return out;
}

Player::Player(const Player& other) : Entity(other), health(other.health), damage(other.damage), xSpeed(other.xSpeed), ySpeed(other.ySpeed), shootingCooldown(other.shootingCooldown) {
    bulletTexture = new sf::Texture();
    std::cout << "Player copy constructor \n";
}

void Player::setBulletTexture(sf::Texture& texture_) {
    bulletTexture = &texture_;
}

void Player::shoot() {
    std::cout << "Player::shoot()\n";

    sf::Vector2f pos = getSprite().getPosition();

    sf::Vector2f pos1 = pos;
    pos1.x += 59.0f;
    pos1.y -= 30.0f;

    sf::Vector2f pos2 = pos;
    pos2.x += 29.0f;
    pos2.y -= 30.0f;

    sf::Vector2f pos3 = pos;
    pos3.x += 89.0f;
    pos3.y -= 30.0f;

    bullets.push_back(new Bullet(pos1, bulletTexture));
    bullets.push_back(new Bullet(pos2, bulletTexture));
    bullets.push_back(new Bullet(pos3, bulletTexture));
}

void Player::drawBullets(sf::RenderWindow& window) {
    for (auto bullet : bullets) {
        window.draw(bullet->getSprite());
    }
}

void Player::loop(std::vector<Enemy*>& enemies) {
    move();
    handleShooting();
    handlePlayerCollision(enemies);
    handleBulletsCollision(enemies);
    shootingCooldown++;
    for (int i = 0; i < (int)bullets.size(); i++) {
        if (bullets[i]->checkCollision()) {
            bullets.erase(bullets.begin() + i);
        }
        bullets[i]->update();
    }

    moveSprite(getVelocity());
}

void Player::handleShooting() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && shootingCooldown > 20) {
        shoot();
        shootingCooldown = 0;
    }
}

void Player::handlePlayerCollision(std::vector<Enemy *> &enemies) {
    sf::FloatRect playerHitbox = getSprite().getGlobalBounds();

    for (auto & enemy : enemies) {
        sf::FloatRect enemyHitbox = enemy->getSprite().getGlobalBounds();

        if (playerHitbox.intersects(enemyHitbox)) {
            health -= 10.0f;
            if (health <= 0.0f) {
                throw PlayerOutOfLivesException();
            }
        }
    }
}

void Player::handleBulletsCollision(std::vector<Enemy*>& enemies) {
    for (int i = (int)bullets.size() - 1; i >= 0; i--) {
        Bullet *currentBullet = bullets[i];
        sf::FloatRect bulletHitbox = currentBullet->getSprite().getGlobalBounds();

        for (int j = 0; j < (int)enemies.size(); j++) {
            sf::FloatRect enemyHitbox = enemies[j]->getSprite().getGlobalBounds();

            if (bulletHitbox.intersects(enemyHitbox)) {
                float bulletDamage = currentBullet->getDamage();
                delete bullets[i];
                bullets.erase(bullets.begin() + i);
                float enemyHp = enemies[j]->getHealth();
                std::cout << enemyHp;
                enemyHp -= bulletDamage;
                if (enemyHp <= 0.0f) {
                    enemies[j]->die();
                    enemies[j]->setIsAlive(false);
                    enemies.erase(enemies.begin() + j);
                    break;
                }
                enemies[j]->setHealth(enemyHp);
                break;
            }
        }
    }
}

void Player::move() {
    auto velocity_ = getVelocity();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        velocity_.x = -xSpeed;
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        velocity_.x = xSpeed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        velocity_.y = -ySpeed;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        velocity_.y = ySpeed;
    }

    if(velocity_.x > 0) {
        velocity_.x -= 0.1f;
    } else if(velocity_.x < 0) {
        velocity_.x += 0.1f;
    }

    if (velocity_.y > 0) {
        velocity_.y -= 0.1f;
    } else if (velocity_.y < 0) {
        velocity_.y += 0.1f;
    }

    if (velocity_.x > -0.2f && velocity_.x < 0.2f) {
        velocity_.x = 0.0f;
    }
    if (velocity_.y > -0.2f && velocity_.y < 0.2f) {
        velocity_.y = 0.0f;
    }

    setVelocity(velocity_);
}