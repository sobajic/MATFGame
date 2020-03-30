#include "precomp.h"
#include "InputManager.h"

#include "ECS/EntityManager.h"

namespace Engine
{
    bool KeyDown(KeyboardButton _iKey)
    {
        short iState = GetAsyncKeyState(static_cast<int>(_iKey));
        return (iState & 0x8000) != 0;
    }

    bool InputManager::Init()
    {
        LOG_INFO("Initializing InputManager");

        InitKeybinds();

        return true;
    }

    void InputManager::ProcessInput()
    {
        for (auto& [action, key] : m_InputActions)
        {
            bool bIsPressed = KeyDown(key);
            switch (m_InputActionStates[action])
            {
            case EInputActionState::None:
            {
                m_InputActionStates[action] = bIsPressed ? EInputActionState::JustPressed : EInputActionState::None;
                break;
            }
            case EInputActionState::JustPressed:
            case EInputActionState::Pressed:
            {
                m_InputActionStates[action] = bIsPressed ? EInputActionState::Pressed : EInputActionState::Released;
                break;
            }
            case EInputActionState::Released:
            {
                m_InputActionStates[action] = bIsPressed ? EInputActionState::JustPressed : EInputActionState::None;
                break;
            }
            default:
                ASSERT("Unknown EInputActionState {0}", m_InputActionStates[action]);
                m_InputActionStates[action] = EInputActionState::None;
                break;
            }
        }
    }

    void InputManager::Update(float dt, EntityManager* entityManager)
    {
        ProcessInput();

        // Update entities
        auto inputComponents = entityManager->GetAllComponentInstances<InputComponent>();

        for (auto component : inputComponents)
        {
            for (auto& action : component->inputActions)
            {
                action.m_Active = IsButtonActionActive(action.m_Action, action.m_ActionTriggerState);
            }
        }
    }

    void InputManager::Shutdown()
    {
        m_InputActions.clear();
        m_InputActionStates.clear();
    }

    bool InputManager::IsButtonActionActive(EInputAction _eAction, EInputActionState _eState) const
    {
        ASSERT(m_InputActionStates.find(_eAction) != m_InputActionStates.end(), "Unknown input action");
        return m_InputActionStates.at(_eAction) == _eState;
    }

    void InputManager::InitKeybinds()
    {
        m_InputActionStates.clear();
        m_InputActionStates.reserve(static_cast<size_t>(EInputAction::InputActionCount));
        m_InputActions.clear();
        m_InputActions.reserve(static_cast<size_t>(EInputAction::InputActionCount));

        m_InputActions[EInputAction::PlayerMoveUp] = VK_UP;
        m_InputActions[EInputAction::PlayerMoveLeft] = VK_LEFT;
        m_InputActions[EInputAction::PlayerMoveDown] = VK_DOWN;
        m_InputActions[EInputAction::PlayerMoveRight] = VK_RIGHT;
        m_InputActions[EInputAction::PauseGame] = VK_ESCAPE;
        m_InputActions[EInputAction::RestartGame] = 'R';
        m_InputActions[EInputAction::PanCameraUp] = 'W';
        m_InputActions[EInputAction::PanCameraLeft] = 'A';
        m_InputActions[EInputAction::PanCameraDown] = 'S';
        m_InputActions[EInputAction::PanCameraRight] = 'D';
    }

}
