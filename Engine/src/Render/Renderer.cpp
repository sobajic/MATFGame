#include "precomp.h"
#include "Renderer.h"
#include "Render/Window.h"
#include "Render/Texture.h"

#include <SDL.h>

namespace Engine
{

    bool Renderer::Init(const WindowData& windowData_)
    {
        LOG_INFO("Initializing Renderer");


        // TODO: Create window and Initialize

        // TODO: Create SDL_Renderer
        // m_NativeRenderer = 

        SetBackgroundColor(100, 150, 236, SDL_ALPHA_OPAQUE);

        return true;
    }

    bool Renderer::Shutdown()
    {
        LOG_INFO("Shutting down Renderer");

        if (m_NativeRenderer != nullptr)
        {
            SDL_DestroyRenderer(m_NativeRenderer);
        }

        m_NativeRenderer = nullptr;

        m_Window.reset();

        return true;
    }

    void Renderer::DrawImage(/* Some image parameters IDK */)
    {
        // TODO: Draw image

        // hint, use SDL_RenderCopy or SDL_RenderCopyEx
    }

    void Renderer::SetBackgroundColor(unsigned char bgR_, unsigned char bgG_, unsigned char bgB_, unsigned char bgA_)
    {
        SDL_SetRenderDrawColor(m_NativeRenderer, bgR_, bgG_, bgB_, bgA_);
    }

    void Renderer::BeginScene() const
    {
        SDL_RenderClear(m_NativeRenderer);
    }

    void Renderer::EndScene() const
    {
        SDL_RenderPresent(m_NativeRenderer);
    }

    Renderer::~Renderer()
    {
        Shutdown();
    }

}