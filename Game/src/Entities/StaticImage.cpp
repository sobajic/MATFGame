#include "precomp.h"

#include "StaticImage.h"

namespace Game
{
    bool StaticImage::Init(Engine::EntityManager* entityManager_, Engine::Texture* texture_)
    {
        ASSERT(texture_ != nullptr, "nullptr passed as texture_");
        ASSERT(entityManager_ != nullptr, "Must pass valid pointer to entitymanager to CameraController::Init()");

        auto imageEntity = std::make_unique<Engine::Entity>();
        imageEntity->AddComponent<Engine::TransformComponent>(100.f, 100.f, 200.f, 200.f);
        imageEntity->AddComponent<Engine::SpriteComponent>().m_Image = texture_;

        entityManager_->AddEntity(std::move(imageEntity));

        return true;
    }
    
    void StaticImage::Update(float dt)
    {

    }
}
