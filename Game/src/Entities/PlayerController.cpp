#include "precomp.h"
#include "PlayerController.h"

namespace Game
{
    bool PlayerController::Init(Engine::EntityManager* entityManager_, Engine::Texture* texture_)
    {
        ASSERT(entityManager_ != nullptr, "Must pass valid pointer to entitymanager to PlayerController::Init()");
        ASSERT(texture_ != nullptr, "Must pass valid pointer to texture to PlayerController::Init()");

        for (int i = 1; i <= 2; ++i)
        {
            auto player = std::make_unique<Engine::Entity>();

            player->AddComponent<Engine::TransformComponent>(i == 1 ? -600 : 600.f, 0.f, 30.f, 100.f);
            player->AddComponent<Engine::CollisionComponent>(30.f, 100.f);
            player->AddComponent<Engine::PlayerComponent>();
            player->AddComponent<Engine::InputComponent>();
            player->AddComponent<Engine::MoverComponent>();
            player->AddComponent<Engine::SpriteComponent>().m_Image = texture_;

            auto inputComp = player->GetComponent<Engine::InputComponent>();

            inputComp->inputActions.push_back({ fmt::format("Player{}MoveUp", i) });
            inputComp->inputActions.push_back({ fmt::format("Player{}MoveDown", i) });

            entityManager_->AddEntity(std::move(player));
        }

        return !(entityManager_->GetAllEntitiesWithComponent<Engine::PlayerComponent>().empty());
    }

    void PlayerController::Update(float dt, Engine::EntityManager* entityManager_)
    {
        auto entitiesToMove = entityManager_->GetAllEntitiesWithComponents<Engine::PlayerComponent, Engine::MoverComponent, Engine::InputComponent>();

        int i = 1;
        for (auto& entity : entitiesToMove)
        {
            auto move = entity->GetComponent<Engine::MoverComponent>();
            auto input = entity->GetComponent<Engine::InputComponent>();
            auto speed = entity->GetComponent<Engine::PlayerComponent>()->m_PanSpeed;

            bool moveUpInput = Engine::InputManager::IsActionActive(input, fmt::format("Player{}MoveUp", i));
            bool moveDownInput = Engine::InputManager::IsActionActive(input, fmt::format("Player{}MoveDown", i));

            move->m_TranslationSpeed.y = speed * ((moveUpInput ? -1.0f : 0.0f) + (moveDownInput ? 1.0f : 0.0f));
            ++i;
        }
    }
}
