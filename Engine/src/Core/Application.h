#pragma once

#include "Render/WindowData.h"

namespace Engine {

    class RenderSystem;

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

    };

    // To be defined in the game
    Application* CreateApplication();

}
