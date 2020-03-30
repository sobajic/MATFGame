#pragma once


struct SDL_Texture;

namespace Engine {

    class Renderer;

    struct Texture
    {
        SDL_Texture* m_Texture{};

        bool LoadTexture(Renderer* renderer_, std::string path_);
        Texture() = default;
        Texture(Renderer* renderer_, std::string path_);
        ~Texture();
    };

    static std::unique_ptr<Texture> CreateTextureFromFilename(Renderer* renderer_, std::string path_)
    {
        auto texture = std::make_unique<Texture>();
        texture->LoadTexture(renderer_, path_);
        return texture;
    }
}
