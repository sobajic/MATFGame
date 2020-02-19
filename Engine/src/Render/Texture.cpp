#include "precomp.h"
#include "Texture.h"
#include "Render/Renderer.h"

#include <SDL_image.h>

namespace Engine
{
    void Texture::LoadTexture(Renderer* renderer_, std::string path_)
    {
        m_Texture = IMG_LoadTexture(renderer_->GetNativeRenderer(), path_.c_str());

        if (m_Texture == nullptr)
        {
            LOG_ERROR("Unable to load texture: {}, SDL_Image returned error {}", path_, IMG_GetError());
        }
    }

    Texture::~Texture()
    {
        if (m_Texture)
        {
            SDL_DestroyTexture(m_Texture);
        }
    }
}