#pragma once
#include "InputAction.h"

using KeyboardButton = int;

namespace Engine
{
    class InputManager
    {
    public:
        bool Init();
        void Update(float dt);
        void Shutdown();

    private:
        void ProcessInput();
        bool IsButtonJustPressed(EInputAction _eAction) const;
        bool IsButtonPressed(EInputAction _eAction) const;
        bool IsButtonReleased(EInputAction _eAction) const;

    private:
        void InitKeybinds();

        std::unordered_map<EInputAction, KeyboardButton> m_InputActions{ };
        std::unordered_map<EInputAction, EInputActionState> m_InputActionStates{ };
    };
}
