#include "precomp.h"
#include "StadiumController.h"

#include "Entities/GameComponents.h"

namespace Game
{
    bool Stadium::Init(Engine::EntityManager* entityManager_, Engine::Texture* texture_)
    {
        ASSERT(entityManager_ != nullptr, "Must pass valid pointer to entitymanager to BallController::Init()");

        // Left
        auto wall = std::make_unique<Engine::Entity>();

        wall->AddComponent<GoalComponent>();
        wall->AddComponent<Engine::TransformComponent>(-635.f, 0.f, 10.f, 800.f);
        wall->AddComponent<Engine::CollisionComponent>(30.f, 800.f);
        wall->AddComponent<Engine::SpriteComponent>().m_Image = texture_;

        entityManager_->AddEntity(std::move(wall));

        // Right
        wall = std::make_unique<Engine::Entity>();

        wall->AddComponent<GoalComponent>();
        wall->AddComponent<Engine::TransformComponent>(635.f, 0.f, 10.f, 800.f);
        wall->AddComponent<Engine::CollisionComponent>(30.f, 800.f);
        wall->AddComponent<Engine::SpriteComponent>().m_Image = texture_;

        entityManager_->AddEntity(std::move(wall));

        // Down
        wall = std::make_unique<Engine::Entity>();

        wall->AddComponent<WallComponent>();
        wall->AddComponent<Engine::TransformComponent>(0.f, 355.f, 1300.f, 30.f);
        wall->AddComponent<Engine::CollisionComponent>(1300.f, 30.f);
        wall->AddComponent<Engine::SpriteComponent>().m_Image = texture_;

        entityManager_->AddEntity(std::move(wall));

        // Up
        wall = std::make_unique<Engine::Entity>();

        wall->AddComponent<WallComponent>();
        wall->AddComponent<Engine::TransformComponent>(0.f, -355.f, 1300.f, 30.f);
        wall->AddComponent<Engine::CollisionComponent>(1300.f, 30.f);
        wall->AddComponent<Engine::SpriteComponent>().m_Image = texture_;

        entityManager_->AddEntity(std::move(wall));

        return true;
    }
}