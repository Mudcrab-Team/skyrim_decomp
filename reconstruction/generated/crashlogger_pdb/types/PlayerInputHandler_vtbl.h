// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PlayerInputHandler_vtbl; size 0x38
#pragma once

struct ButtonEvent;
struct MotionGestureEvent;
struct MouseMoveEvent;
struct PlayerControlsData;
struct SixaxisEvent;
struct ThumbstickEvent;
struct PlayerInputHandler_vtbl {
    void (*_dtor_PlayerInputHandler)(void);
    bool (*CanProcess)(char32_t* );
    void (*ProcessMotionGesture)(MotionGestureEvent* , PlayerControlsData* );
    void (*ProcessSixaxis)(SixaxisEvent* , PlayerControlsData* );
    void (*ProcessThumbstick)(ThumbstickEvent* , PlayerControlsData* );
    void (*ProcessMouseMove)(MouseMoveEvent* , PlayerControlsData* );
    void (*ProcessButton)(ButtonEvent* , PlayerControlsData* );
};
static_assert(sizeof(PlayerInputHandler_vtbl) == 56, "PlayerInputHandler_vtbl layout differs from the PDB");
