#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

class Entity
{
    private:
        sf::Texture *texture;
        sf::Sprite sprite;
        sf::Vector2f position;
        sf::Vector2f velocity;
        bool isAlive;

    public:
        Entity() = default;
        Entity(sf::Texture& texture, sf::Vector2f position);
        Entity(const Entity& obj);
        Entity& operator=(const Entity& obj);
        virtual ~Entity() = default;

        void setTexture(sf::Texture* texture);
        void setPosition(sf::Vector2f position);
        void setVelocity(sf::Vector2f velocity);
        void setIsAlive(bool isAlive);

        friend std::ostream& operator<<(std::ostream& os, const Entity& entity);
        sf::Sprite& getSprite();
        sf::Vector2f getPosition();
        sf::Vector2f& getVelocity();
        bool getIsAlive() const;

        void moveSprite(sf::Vector2f offset);

        virtual void update();
        virtual void draw(sf::RenderWindow &window);
};
