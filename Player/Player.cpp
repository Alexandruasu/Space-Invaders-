#include "Player.h"

#include <iostream>

Player::Player() {
    std::cout << "Player constructor \n";
    health = 100.0f;
    damage = 10.0f;
    xSpeed = 4.0f;
    ySpeed = 3.0f;
    shootingCooldown = 0;
    velocity = sf::Vector2f(0.0f, 0.0f);
    bullets = std::vector<Bullet>();
    texture = sf::Texture();
    sprite.setPosition({ 400.0f, 500.0f });
}

Player::~Player() {
    std::cout << "Player destructor \n";
}

Player& Player::operator=(const Player& other) {
    std::cout << "Player assignment operator \n";

    health = other.health;
    damage = other.damage;
    xSpeed = other.xSpeed;
    ySpeed = other.ySpeed;
    texture = other.texture;
    sprite = other.sprite;

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Player& player) {
    out << "Health: " << player.health << "\n Damage: " << player.damage << "\n";
    return out;
}

Player::Player(const Player& other) {
    std::cout << "Player copy constructor \n";

    shootingCooldown = other.shootingCooldown;
    health = other.health;
    damage = other.damage;
    xSpeed = other.xSpeed;
    ySpeed = other.ySpeed;
    texture = other.texture;
    sprite = other.sprite;
}

void Player::shoot() {
    std::cout << "Player::shoot()\n";

    sf::Vector2f pos = sprite.getPosition();

    sf::Vector2f pos1 = pos;
    pos1.x += 59.0f;
    pos1.y -= 30.0f;

    sf::Vector2f pos2 = pos;
    pos2.x += 29.0f;
    pos2.y -= 30.0f;

    sf::Vector2f pos3 = pos;
    pos3.x += 89.0f;
    pos3.y -= 30.0f;

    Bullet bullet = Bullet(pos1);
    bullets.push_back(bullet);

    Bullet bullet2 = Bullet(pos2);
    bullets.push_back(bullet2);

    Bullet bullet3 = Bullet(pos3);
    bullets.push_back(bullet3);
}

void Player::loop(Enemy* enemies, int enemyCount) {
    move();
    handleShooting();
    handleBulletsCollision(enemies, enemyCount);
    shootingCooldown++;
    for (int i = 0; i < (int)bullets.size(); i++) {
        if (bullets[i].checkCollision()) {
            bullets.erase(bullets.begin() + i);
        }
        bullets[i].update();
    }

    sprite.move(velocity);
}

void Player::setTexture(const sf::Texture& texture_) {
    texture = texture_;
    sprite.setTexture(texture);
}

void Player::handleShooting() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && shootingCooldown > 20) {
        shoot();
        shootingCooldown = 0;
    }
}

void Player::handleBulletsCollision(Enemy* enemies, int enemyCount) {
    int bulletCount = getBulletCount();

    for (int i = 0; i < bulletCount; i++) {
        Bullet currentBullet = bullets[i];
        sf::FloatRect bulletHitbox = currentBullet.getSprite().getGlobalBounds();

        for (int j = 0; j < enemyCount; j++) {
            sf::FloatRect enemyHitbox = enemies[j].getSprite().getGlobalBounds();

            if (bulletHitbox.intersects(enemyHitbox)) {
                bullets.erase(bullets.begin() + i);
                float enemyHp = enemies[j].getHealth();
                std::cout << enemyHp;
                enemyHp -= currentBullet.getDamage();
                if (enemyHp <= 0.0f)
                    enemies[j].die();
                enemies[j].setHealth(enemyHp);
            }
        }
    }
}

void Player::move() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        velocity.x = -xSpeed;
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        velocity.x = xSpeed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        velocity.y = -ySpeed;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        velocity.y = ySpeed;
    }

    // decelerate to 0
    if(velocity.x > 0) {
        velocity.x -= 0.1f;
    } else if(velocity.x < 0) {
        velocity.x += 0.1f;
    }

    if (velocity.y > 0) {
        velocity.y -= 0.1f;
    } else if (velocity.y < 0) {
        velocity.y += 0.1f;
    }

    // stop at 0
    if (velocity.x > -0.2f && velocity.x < 0.2f) {
        velocity.x = 0.0f;
    }
    if (velocity.y > -0.2f && velocity.y < 0.2f) {
        velocity.y = 0.0f;
    }
}