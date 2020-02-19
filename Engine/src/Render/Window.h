#pragma once
#include "Render/WindowData.h"

struct SDL_Window;

namespace Engine {

    struct WindowData;

    class Window
    {
    public:
        bool Init(const WindowData& windowData_ = WindowData());
        bool Shutdown();
        SDL_Window* GetNativeWindowHandle() const { return m_NativeWindowHandle; }
        ~Window();
    private:
        WindowData m_WindowData{};
        SDL_Window* m_NativeWindowHandle{ };
    };
}