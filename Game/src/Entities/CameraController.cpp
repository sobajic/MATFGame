#include "precomp.h"

#include "CameraController.h"

namespace Game
{

    bool CameraController::Init(Engine::EntityManager* entityManager_)
    {
        ASSERT(entityManager_ != nullptr, "Must pass valid pointer to entitymanager to CameraController::Init()");

        auto camera = std::make_unique<Engine::Entity>();
        camera->AddComponent<Engine::TransformComponent>();
        camera->AddComponent<Engine::CameraComponent>(100.f);
        camera->AddComponent<Engine::InputComponent>();
        camera->AddComponent<Engine::MoverComponent>();

        auto transformComp = camera->GetComponent<Engine::TransformComponent>();
        transformComp->m_Size = { 1280.f, 720.f };

        auto inputComp = camera->GetComponent<Engine::InputComponent>();

        inputComp->inputActions.push_back({ "PanCameraUp" });
        inputComp->inputActions.push_back({ "PanCameraDown" });
        inputComp->inputActions.push_back({ "PanCameraRight" });
        inputComp->inputActions.push_back({ "PanCameraLeft" });

        entityManager_->AddEntity(std::move(camera));

        return !(entityManager_->GetAllEntitiesWithComponent<Engine::CameraComponent>().empty());
    }

    void CameraController::Update(float dt, Engine::EntityManager* entityManager_)
    {
        auto entitiesToMove = entityManager_->GetAllEntitiesWithComponents<Engine::CameraComponent, Engine::MoverComponent, Engine::InputComponent>();

        for (auto& entity : entitiesToMove)
        {
            auto move = entity->GetComponent<Engine::MoverComponent>();
            auto input = entity->GetComponent<Engine::InputComponent>();
            auto speed = entity->GetComponent<Engine::CameraComponent>()->m_PanSpeed;

            bool moveUpInput = Engine::InputManager::IsActionActive(input, "PanCameraUp");
            bool moveDownInput = Engine::InputManager::IsActionActive(input, "PanCameraDown");
            bool moveLeftInput = Engine::InputManager::IsActionActive(input, "PanCameraLeft");
            bool moveRightInput = Engine::InputManager::IsActionActive(input, "PanCameraRight");

            move->m_TranslationSpeed.x = speed * ((moveLeftInput ? -1.0f : 0.0f) + (moveRightInput ? 1.0f : 0.0f));
            move->m_TranslationSpeed.y = speed * ((moveUpInput ? -1.0f : 0.0f) + (moveDownInput ? 1.0f : 0.0f));
        }
    }
}
