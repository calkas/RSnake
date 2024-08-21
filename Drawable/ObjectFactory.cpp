#include "ObjectFactory.hpp"
#include "ResourceManager.hpp"
#include <SFML/Graphics.hpp>

namespace RSnakeGame
{
ObjectFactory *ObjectFactory::Instance()
{
    static ObjectFactory instance;
    return &instance;
}

std::shared_ptr<DrawableObject> ObjectFactory::CreateFruit(Point2D coord, int w, int h, float rot, float scale)
{
    std::optional<std::shared_ptr<sf::Texture>> texture = ResourceManager::Instance()->GetTexture(Texture::FRUIT);
    auto block = std::make_shared<DrawableObject>(coord, w, h, rot, scale, pRenderer);
    block->texture = texture;
    return block;
}

std::shared_ptr<DrawableObject> ObjectFactory::CreateBoardBlock(const char *pTextureName, Point2D coord, int w, int h,
                                                                float rot, float scale)
{
    std::optional<std::shared_ptr<sf::Texture>> texture = ResourceManager::Instance()->GetTexture(pTextureName);
    auto block = std::make_shared<DrawableObject>(coord, w, h, rot, scale, pRenderer);
    block->texture = texture;
    return block;
}

std::shared_ptr<DrawableObject> ObjectFactory::CreateSnakeBody(SnakeBlockType snakeBodyType, Point2D coord, int w,
                                                               int h, float rot, float scale, float velocity)
{
    std::optional<std::shared_ptr<sf::Texture>> texture;

    switch (snakeBodyType)
    {
    case SnakeBlockType::HEAD:
        texture = ResourceManager::Instance()->GetTexture(Texture::SNAKE_HEAD);
        break;
    case SnakeBlockType::BODY:
        texture = ResourceManager::Instance()->GetTexture(Texture::SNAKE_BODY);
        break;
    case SnakeBlockType::TAIL:
        texture = ResourceManager::Instance()->GetTexture(Texture::SNAKE_TAIL);
        break;
    }

    auto block = std::make_shared<DrawableObject>(coord, w, h, rot, scale, pRenderer);
    block->texture = texture;
    block->velocity = velocity;
    return block;
}

void ObjectFactory::SetRenderer(sf::RenderWindow *pRenderWindow)
{
    pRenderer = pRenderWindow;
}

} // namespace RSnakeGame
