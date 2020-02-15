#include "Application.h"
#include "Logger/Logger.h"

namespace Engine {

    bool Application::Init()
    {
        LOG_INFO("Initializing application");

        // Main Renderer initialize

        // Window initialize

        // InputManager initialize

        // Entity Manager initialize

        // Render system initialize

        // Camera Controller initialize

        // Physics system initialize

        return true;
    }

    bool Application::Shutdown()
    {
        LOG_INFO("Shutting down application");

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
    }

}