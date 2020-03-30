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

        inputComp->inputActions.push_back({ Engine::EInputAction::PanCameraRight });
        inputComp->inputActions.push_back({ Engine::EInputAction::PanCameraUp });
        inputComp->inputActions.push_back({ Engine::EInputAction::PanCameraDown });
        inputComp->inputActions.push_back({ Engine::EInputAction::PanCameraLeft });

        entityManager_->AddEntity(std::move(camera));

        return !(entityManager_->GetAllEntitiesWithComponent<Engine::CameraComponent>().empty());
    }

    bool IsActionActive(Engine::InputComponent* inputComponent, Engine::EInputAction targetAction)
    {
        auto found = std::find_if(
            std::begin(inputComponent->inputActions),
            std::end(inputComponent->inputActions),
            [targetAction](Engine::InputAction e)
            {
                return e.m_Action == targetAction && e.m_Active == true;
            });

        return found != std::end(inputComponent->inputActions);
    }

    void CameraController::Update(float dt, Engine::EntityManager* entityManager_)
    {
        auto entitiesToMove = entityManager_->GetAllEntitiesWithComponents<Engine::CameraComponent, Engine::MoverComponent, Engine::InputComponent>();

        for (auto& entity : entitiesToMove)
        {
            auto move = entity->GetComponent<Engine::MoverComponent>();
            auto input = entity->GetComponent<Engine::InputComponent>();
            auto speed = entity->GetComponent<Engine::CameraComponent>()->m_PanSpeed;

            bool moveUpInput = IsActionActive(input, Engine::EInputAction::PanCameraUp);
            bool moveDownInput = IsActionActive(input, Engine::EInputAction::PanCameraDown);
            bool moveLeftInput = IsActionActive(input, Engine::EInputAction::PanCameraLeft);
            bool moveRightInput = IsActionActive(input, Engine::EInputAction::PanCameraRight);

            move->m_TranslationSpeed.x = speed * (moveLeftInput ? -1.0f : 0.0f + moveRightInput ? 1.0f : 0.0f);
            move->m_TranslationSpeed.y = speed * (moveUpInput ? -1.0f : 0.0f + moveDownInput ? 1.0f : 0.0f);
        }
    }
}
