#include "precomp.h"
#include "RenderSystem.h"
#include "Render/Renderer.h"
#include "Render/Window.h"

#include <SDL.h>
#include <SDL_Image.h>

namespace Engine
{
    bool RenderSystem::Init(const WindowData& windowData_)
    {
        LOG_INFO("Initializing RenderSystem");

        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            LOG_CRITICAL("Unable to initialize SDL. SDL error: {}", SDL_GetError());
            return false;
        }

        if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) < 0)
        {
            LOG_CRITICAL("Unable to initialize SDL_Image");
            return false;
        }

        m_Renderer = std::make_unique<Renderer>();

        if (!m_Renderer->Init(windowData_))
        {
            LOG_CRITICAL("Unable to initialize renderer");
            return false;
        }

        m_Renderer->Init(windowData_);

        LOG_INFO("RenderSystem initialized successfully");
        return true;
    }

    bool RenderSystem::Shutdown()
    {
        LOG_INFO("Shutting down RenderSystem");

        m_Renderer.reset();
        SDL_Quit();

        return true;
    }

    void RenderSystem::Update(float dt_/*, EntityManager* entityManager*/)
    {
        LOG_INFO("RenderSystem::Update");

        m_Renderer->BeginScene();

        // Find all images to draw

        // Draw every image
        do
        {
            m_Renderer->DrawImage();
        } while (false);

        m_Renderer->EndScene();
    }
}
