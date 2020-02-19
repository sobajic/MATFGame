#pragma once
#include "Render/WindowData.h"

#include "Render/Texture.h" // TODO: Remove after testing

struct SDL_Renderer;

namespace Engine
{
    struct WindowData;
    class Window;

    class Renderer
    {
    public:
        bool Init(const WindowData& windowData_ = WindowData());
        bool Shutdown();

        void DrawImage(/* Some image parameters IDK */);
        void BeginScene() const;
        void EndScene() const;

        SDL_Renderer* GetNativeRenderer() const { return m_NativeRenderer; }

        void SetBackgroundColor(unsigned char bgR_, unsigned char bgG_, unsigned char bgB_, unsigned char bgA_);
        ~Renderer();

    private:
        std::unique_ptr<Window> m_Window;
        SDL_Renderer* m_NativeRenderer{ };

        Texture m_helloWorldTexture; // TODO: Remove after testing
    };
}