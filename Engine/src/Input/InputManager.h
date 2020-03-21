#pragma once
#include "InputAction.h"

using KeyboardButton = int;

namespace Engine
{
    class EntityManager;

    class InputManager
    {
    public:
        bool Init();
        void Update(float dt);
        void Shutdown();

    private:
        void ProcessInput();
        bool IsButtonActionActive(EInputAction _eAction, EInputActionState _eState) const;
        void InitKeybinds();

        std::unordered_map<EInputAction, KeyboardButton> m_InputActions{ };
        std::unordered_map<EInputAction, EInputActionState> m_InputActionStates{ };
    };
}
