#pragma once
#include "Render/WindowData.h"

namespace Engine
{
    struct WindowData;
    class Renderer;

    class RenderSystem
    {
    public:
        bool Init(const WindowData& windowData_ = WindowData());
        bool Shutdown();
        void Update(float dt_/*, EntityManager* entityManager*/);
    private:
        std::unique_ptr<Renderer> m_Renderer;
    };
}