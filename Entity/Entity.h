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

    public:
        Entity() = default;
        Entity(sf::Texture& texture, sf::Vector2f position);
        Entity(const Entity& obj);
        Entity& operator=(const Entity& obj);
        virtual ~Entity() = default;

        virtual void setTexture(sf::Texture* texture);
        virtual void setPosition(sf::Vector2f position);
        virtual void setVelocity(sf::Vector2f velocity);

        friend std::ostream& operator<<(std::ostream& os, const Entity& entity);

        sf::Texture getTexture();
        sf::Sprite& getSprite();
        sf::Vector2f getPosition();
        sf::Vector2f& getVelocity();

        void moveSprite(sf::Vector2f offset);

        virtual void update();
        virtual void draw(sf::RenderWindow &window);
};
