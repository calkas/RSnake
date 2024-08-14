#include "ResourceManager.hpp"
#include <SFML/Graphics.hpp>

namespace RSnakeGame
{
ResourceManager *ResourceManager::Instance()
{
    static ResourceManager instance;
    return &instance;
}
bool ResourceManager::LoadTexture(std::filesystem::path &path, std::string_view textureName)
{
    std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
    if (!texture->loadFromFile(path.string()))
        return false;
    m_Textures.insert(TextureMapElement(textureName.data(), texture));
    return true;
}
bool ResourceManager::LoadFont(std::filesystem::path &path, std::string_view fontName)
{

    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
    if (!font->loadFromFile(path.string()))
        return false;

    m_Fonts.insert(FontMapElement(fontName.data(), font));
    return true;
}

std::shared_ptr<sf::Texture> ResourceManager::GetTexture(std::string_view textureName) const
{
    if (m_Textures.contains(textureName.data()))
    {
        return m_Textures.at(textureName.data());
    }

    return nullptr;
}
std::shared_ptr<sf::Font> ResourceManager::GetFont(std::string_view fontName) const
{
    if (m_Fonts.contains(fontName.data()))
    {
        return m_Fonts.at(fontName.data());
    }
    return nullptr;
}

} // namespace RSnakeGame
