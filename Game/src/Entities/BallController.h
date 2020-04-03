#pragma once

namespace Engine
{
    class EntityManager;
    class TextureManager;
}

namespace Game
{
    class BallController
    {
    public:
        bool Init(Engine::EntityManager* entityManager_, Engine::Texture* texture_);
        void Update(float dt, Engine::EntityManager* entityManager_);
    };
}
