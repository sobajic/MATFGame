#pragma once

namespace Engine
{
    class EntityManager;
}

namespace Game
{

    class CameraController
    {
    public:
        bool Init(Engine::EntityManager* entityManager_);
        void Update(float dt, Engine::EntityManager* entityManager_);
    };
}
