#include "precomp.h"
#include "InputManager.h"

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
        // TODO: Implement
        for (auto& [action, key] : m_InputActions)
        {
            bool bIsPressed = KeyDown(key);
            switch (m_InputActionStates[action])
            {
            case EInputActionState::None:

            case EInputActionState::JustPressed:

            case EInputActionState::Pressed:

            case EInputActionState::Released:

            default:
                ASSERT("Unknown EInputActionState {0}", m_InputActionStates[action]);
                m_InputActionStates[action] = EInputActionState::None;
                break;
            }
        }
    }

    void InputManager::Update(float dt)
    {
        ProcessInput();

        // Update entities
    }

    void InputManager::Shutdown()
    {
        m_InputActions.clear();
        m_InputActionStates.clear();
    }

    bool InputManager::IsButtonJustPressed(EInputAction _eAction) const
    {
        ASSERT(m_InputActionStates.find(_eAction) != m_InputActionStates.end(), "Unknown input action");
        return m_InputActionStates.at(_eAction) == EInputActionState::JustPressed;
    }

    bool InputManager::IsButtonPressed(EInputAction _eAction) const
    {
        ASSERT(m_InputActionStates.find(_eAction) != m_InputActionStates.end(), "Unknown input action");
        return m_InputActionStates.at(_eAction) == EInputActionState::Pressed;
    }

    bool InputManager::IsButtonReleased(EInputAction _eAction) const
    {
        ASSERT(m_InputActionStates.find(_eAction) != m_InputActionStates.end(), "Unknown input action");
        return m_InputActionStates.at(_eAction) == EInputActionState::Released;
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
    }

}