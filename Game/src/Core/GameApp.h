#pragma once

#include <Core\Application.h>

namespace Game
{
    class CameraController;
    class StaticImage;

    class GameApp final : public Engine::Application
    {
    private:
        void GameSpecificWindowData() override;
        bool GameSpecificInit() override;
        void GameSpecificUpdate(float dt) override;
        bool GameSpecificShutdown() override;

        std::unique_ptr<CameraController> m_CameraController{};
        std::unique_ptr<StaticImage> m_TestImage{};
    };

}

Engine::Application* Engine::CreateApplication()
{
    return new Game::GameApp();
}
