#pragma once

namespace Engine {

    class Application
    {
    public:
        virtual bool Init();
        virtual bool Shutdown();
        int Run();

        virtual ~Application() = default;

    private:
        virtual void Update(float dt);
        bool m_Running{ false };
    };
}
