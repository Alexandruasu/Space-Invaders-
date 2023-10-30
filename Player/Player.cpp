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
    texture.loadFromFile("./Assets/Textures/Player.png");
    sprite.setTexture(texture);
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
    pos.x += 59.0f;
    pos.y -= 30.0f;
    Bullet bullet = Bullet(pos);
    bullets.push_back(bullet);
}

void Player::loop(Enemy** enemies, int enemyCount, EnemyRow row) {
    move();
    handleShooting();
    handleBulletsCollision(enemies, enemyCount, row);
    shootingCooldown++;
    for (int i = 0; i < (int)bullets.size(); i++) {
        if (bullets[i].checkCollision()) {
            bullets.erase(bullets.begin() + i);
        }
        bullets[i].update();
    }

    sprite.move(velocity);
}

void Player::handleShooting() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && shootingCooldown > 20) {
        shoot();
        shootingCooldown = 0;
    }
}

void Player::handleBulletsCollision(Enemy** enemies, int enemyCount, EnemyRow row) {
    int bulletCount = getBulletCount();

    for (int i = 0; i < bulletCount; i++) {
        Bullet currentBullet = bullets[i];
        sf::FloatRect bulletHitbox = currentBullet.getSprite().getGlobalBounds();

        for (int j = 0; j < enemyCount; j++) {
            Enemy* currentEnemy = enemies[j];
            sf::FloatRect enemyHitbox = currentEnemy->getSprite().getGlobalBounds();

            if (bulletHitbox.intersects(enemyHitbox)) {
                float enemyHp = currentEnemy->getHealth();
                enemyHp -= currentBullet.getDamage();
                if (enemyHp <= 0.0f) {
                    row.killEnemy(j);
                }
                currentEnemy->setHealth(enemyHp);
                bullets.erase(bullets.begin() + i);
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