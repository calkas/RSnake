#pragma once
#include <filesystem>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>

namespace sf
{
class Texture;
class Font;
} // namespace sf

namespace RSnakeGame
{
class ResourceManager
{
    using TextureMapElement = std::pair<std::string, std::shared_ptr<sf::Texture>>;
    using FontMapElement = std::pair<std::string, std::shared_ptr<sf::Font>>;

  public:
    static ResourceManager *Instance();

    bool LoadTexture(std::filesystem::path &path, std::string_view textureName);
    bool LoadFont(std::filesystem::path &path, std::string_view fontName);

    std::optional<std::shared_ptr<sf::Texture>> GetTexture(std::string_view textureName) const;
    std::optional<std::shared_ptr<sf::Font>> GetFont(std::string_view fontName) const;

  private:
    ResourceManager() = default;
    std::unordered_map<std::string, std::shared_ptr<sf::Texture>> m_Textures{};
    std::unordered_map<std::string, std::shared_ptr<sf::Font>> m_Fonts{};
};

} // namespace RSnakeGame
