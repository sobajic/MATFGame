#pragma once

namespace Engine
{
    class EntityManager;
    struct Texture;
}

namespace Game
{

    class StaticImage
    {
    public:
        bool Init(Engine::EntityManager* entityManager_, Engine::Texture* texture_);
        void Update(float dt);
    };
}
