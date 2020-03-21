#pragma once

#include "Render/WindowData.h"

namespace Engine {

    class RenderSystem;
    class InputManager;
    class EntityManager;

    class Application
    {
    public:
        virtual bool Init();
        virtual bool Shutdown();
        int Run();


        virtual ~Application() = default;

    protected:
        void SetWindowData(const WindowData& windowData_) { m_WindowData = windowData_; }

    private:
        virtual void Update(float dt);
        bool m_Running{ false };

        WindowData m_WindowData{};
        std::unique_ptr<RenderSystem> m_RenderSystem;
        std::unique_ptr<InputManager> m_InputManager;
        std::unique_ptr<EntityManager> m_EntityManager;
    };

    // To be defined in the game
    Application* CreateApplication();
}
