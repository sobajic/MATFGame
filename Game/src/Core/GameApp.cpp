#include "precomp.h"

#include "GameApp.h"
#include "Entities/CameraController.h"
#include "Entities/PlayerController.h"
#include "Entities/BallController.h"
#include "Entities/StadiumController.h"
#include "Entities/StaticImage.h"

#include <Engine.h>
#include <Core/EntryPoint.h>


void Game::GameApp::GameSpecificWindowData()
{
    Engine::WindowData gameSpecificWindowData;
    gameSpecificWindowData.m_Title = "Nikola's Pong";
    gameSpecificWindowData.m_Width = 1280;
    gameSpecificWindowData.m_Height = 720;
    // gameSpecificWindowData.m_Vsync = true;
    SetWindowData(gameSpecificWindowData);
}

bool Game::GameApp::GameSpecificInit()
{
    m_RenderSystem->SetBackgroundColor(0, 0, 0, 1);

    m_CameraController = std::make_unique<CameraController>();
    m_CameraController->Init(m_EntityManager.get());

    // TestImage
    m_TextureManager->CreateTexture(m_RenderSystem->GetRenderer(), "blank", "blank.png");
    m_TextureManager->CreateTexture(m_RenderSystem->GetRenderer(), "hello", "hello_world.jpg");
    m_TestImage = std::make_unique<StaticImage>();
    m_TestImage->Init(m_EntityManager.get(), m_TextureManager->GetTexture("hello"));

    m_PlayerController = std::make_unique<PlayerController>();
    m_PlayerController->Init(m_EntityManager.get(), m_TextureManager->GetTexture("blank"));

    m_BallController = std::make_unique<BallController>();
    m_BallController->Init(m_EntityManager.get(), m_TextureManager->GetTexture("blank"));

    m_Stadium = std::make_unique<Stadium>();
    m_Stadium->Init(m_EntityManager.get(), m_TextureManager->GetTexture("blank"));

    return true;
}

void Game::GameApp::GameSpecificUpdate(float dt)
{
    m_PlayerController->Update(dt, m_EntityManager.get());
    m_CameraController->Update(dt, m_EntityManager.get());
    m_BallController->Update(dt, m_EntityManager.get());
}

bool Game::GameApp::GameSpecificShutdown()
{
    return true;
}
