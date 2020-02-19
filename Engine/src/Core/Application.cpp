#include "precomp.h"
#include "Application.h"
#include "Render/RenderSystem.h"
#include "Render/Renderer.h"
#include "Render/Window.h"
#include "Render/WindowData.h"

namespace Engine {

    bool Application::Init()
    {
        LOG_INFO("Initializing application");

        // Render system initialize
        m_RenderSystem = std::make_unique<RenderSystem>();
        if (!m_RenderSystem->Init(m_WindowData))
        {
            LOG_CRITICAL("Failed to initialize RenderSystem");
            return false;
        }

        // InputManager initialize

        // Entity Manager initialize

        // Camera Controller initialize

        // Physics system initialize

        return true;
    }

    bool Application::Shutdown()
    {
        LOG_INFO("Shutting down application");

        m_RenderSystem->Shutdown();
        m_RenderSystem.reset();

        return true;
    }

    int Application::Run()
    {
        m_Running = true;

        // Main loop
        while (true)
        {
            float argumentForUpdate = 1.0f; // TODO: Remove
            Update(argumentForUpdate);
        }

        m_Running = false;

        return 0;
    }

    void Application::Update(float dt)
    {
        // Update all systems
        m_RenderSystem->Update(dt);
    }

    Engine::Application* CreateApplication()
    {
        return new Engine::Application();
    }

}