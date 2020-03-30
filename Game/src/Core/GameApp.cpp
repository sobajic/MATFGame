#include "precomp.h"

#include "GameApp.h"
#include "Entities/CameraController.h"
#include "Entities/StaticImage.h"

#include <Engine.h>
#include <Core/EntryPoint.h>


void Game::GameApp::GameSpecificWindowData()
{
    Engine::WindowData gameSpecificWindowData;
    gameSpecificWindowData.m_Title = "Nikola's Pong";
    // gameSpecificWindowData.m_Vsync = true;
    SetWindowData(gameSpecificWindowData);
}

bool Game::GameApp::GameSpecificInit()
{
    m_RenderSystem->SetBackgroundColor(0, 0, 0, 1);

    m_CameraController->Init(m_EntityManager.get());

    // TestImage
    m_TextureManager->CreateTexture(m_RenderSystem->GetRenderer(), "hello", "hello_world.jpg");
    m_TestImage = std::make_unique<StaticImage>();
    m_TestImage->Init(m_EntityManager.get(), m_TextureManager->GetTexture("hello"));

    return true;
}

void Game::GameApp::GameSpecificUpdate(float dt)
{
    m_CameraController->Update(dt, m_EntityManager.get());
}

bool Game::GameApp::GameSpecificShutdown()
{
    return true;
}
