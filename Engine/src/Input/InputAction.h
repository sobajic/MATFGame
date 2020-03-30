#pragma once

namespace Engine {

    enum class EInputActionState
    {
        None = 0,
        JustPressed,
        Pressed,
        Released,

        InputActionStateCount
    };

    enum class EInputAction
    {
        PlayerMoveLeft = 0,
        PlayerMoveRight,
        PlayerMoveUp,
        PlayerMoveDown,
        PlayerFire,
        PlayerJump,
        PlayerAccelerate,
        Player2MoveLeft,
        Player2MoveRight,
        Player2MoveUp,
        Player2MoveDown,
        Player2Fire,
        Player2Jump,
        Player2Accelerate,
        PanCameraLeft,
        PanCameraRight,
        PanCameraUp,
        PanCameraDown,
        ToggleDebugMode,
        PauseGame,
        RestartGame,
        MenuSelect,

        InputActionCount
    };

    struct InputAction
    {
        EInputAction m_Action{ EInputAction::InputActionCount };
        EInputActionState m_ActionTriggerState{ EInputActionState::Pressed };
        bool m_Active{ false };

        InputAction(EInputAction action_, EInputActionState activeState_ = EInputActionState::Pressed) : m_Action(action_), m_ActionTriggerState(activeState_) { }
    };
}
