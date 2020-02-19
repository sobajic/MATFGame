#pragma once

#include <SDL.h>

struct SDL_Texture;

namespace Engine {

    class Renderer;

    struct Texture
    {
        SDL_Texture* m_Texture{};

        void LoadTexture(Renderer* renderer_, std::string path_);
        ~Texture();
    };
}