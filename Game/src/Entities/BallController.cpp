#include "precomp.h"
#include "BallController.h"

#include "Entities/GameComponents.h"

#include <random>

namespace Game
{
    static float GetRandomSpeed()
    {
        std::random_device rd;
        std::uniform_int_distribution<int> spd(100, 250);
        std::discrete_distribution<> direction({ 50, 0, 50 });

        return spd(rd) * (direction(rd) - 1.f);
    }

    bool BallController::Init(Engine::EntityManager* entityManager_, Engine::Texture* texture_)
    {
        ASSERT(entityManager_ != nullptr, "Must pass valid pointer to entitymanager to BallController::Init()");
        ASSERT(texture_ != nullptr, "Must pass valid pointer to texture to BallController::Init()");

        auto ball = std::make_unique<Engine::Entity>();

        ball->AddComponent<BallComponent>();
        ball->AddComponent<Engine::TransformComponent>(0.f, 0.f, 30.f, 30.f);
        ball->AddComponent<Engine::CollisionComponent>(30.f, 30.f);
        ball->AddComponent<Engine::MoverComponent>(GetRandomSpeed(), GetRandomSpeed());
        ball->AddComponent<Engine::SpriteComponent>().m_Image = texture_;

        entityManager_->AddEntity(std::move(ball));

        return true;
    }

    void BallController::Update(float dt, Engine::EntityManager* entityManager_)
    {
        auto balls = entityManager_->GetAllEntitiesWithComponent<BallComponent>();

        for (auto& ball : balls)
        {
            auto collider = ball->GetComponent<Engine::CollisionComponent>();

            for (const auto& entity : collider->m_CollidedWith)
            {
                if (entity->HasComponent<Engine::PlayerComponent>())
                {
                    auto mover = ball->GetComponent<Engine::MoverComponent>();
                    mover->m_TranslationSpeed = { mover->m_TranslationSpeed.x * -1.f, mover->m_TranslationSpeed.y };
                }

                if (entity->HasComponent<WallComponent>())
                {
                    auto mover = ball->GetComponent<Engine::MoverComponent>();
                    mover->m_TranslationSpeed = { mover->m_TranslationSpeed.x, mover->m_TranslationSpeed.y * -1.f };
                }

                if (entity->HasComponent<GoalComponent>())
                {
                    auto mover = ball->GetComponent<Engine::MoverComponent>();
                    mover->m_TranslationSpeed = { GetRandomSpeed(), GetRandomSpeed() };

                    auto transform = ball->GetComponent<Engine::TransformComponent>();
                    transform->m_Position.x = 0.f;
                    transform->m_Position.y = 0.f;
                }
            }
        }
    }
}
