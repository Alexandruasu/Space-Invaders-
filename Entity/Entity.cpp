#include "Entity.h"

Entity::Entity(sf::Texture& texture, sf::Vector2f position)
{
    this->texture = &texture;
    this->sprite.setTexture(*this->texture);
    this->position = position;
    this->sprite.setPosition(this->position);
    this->isAlive = true;
}

Entity::Entity(const Entity& obj)
{
    this->texture = obj.texture;
    this->sprite = obj.sprite;
    this->position = obj.position;
    this->velocity = obj.velocity;
    this->isAlive = obj.isAlive;
}

Entity& Entity::operator=(const Entity& obj)
{
    if (&obj == this)
    {
        return *this;
    }
    this->texture = obj.texture;
    this->sprite = obj.sprite;
    this->position = obj.position;
    this->velocity = obj.velocity;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Entity &entity)
{
    os << "Entity: \n"
       << "Position: (" << entity.position.x << ", " << entity.position.y << ")\n"
       << "Velocity: (" << entity.velocity.x << ", " << entity.velocity.y << ")\n";
    return os;
}

void Entity::setIsAlive(bool isAlive_)
{
    this->isAlive = isAlive_;
}

void Entity::setTexture(sf::Texture* texture_)
{
    this->texture = texture_;
    this->sprite.setTexture(*this->texture);
}

void Entity::setPosition(sf::Vector2f position_)
{
    this->position = position_;
    this->sprite.setPosition(this->position);
}

void Entity::setVelocity(sf::Vector2f velocity_)
{
    this->velocity = velocity_;
}

bool Entity::getIsAlive() const
{
    return this->isAlive;
}

sf::Sprite& Entity::getSprite()
{
    return this->sprite;
}

sf::Vector2f Entity::getPosition()
{
    return this->position;
}

sf::Vector2f& Entity::getVelocity()
{
    return this->velocity;
}

void Entity::moveSprite(sf::Vector2f offset)
{
    this->sprite.move(offset);
}

void Entity::update()
{
    this->moveSprite(this->velocity);
}

void Entity::draw(sf::RenderWindow &window)
{
    window.draw(this->sprite);
}