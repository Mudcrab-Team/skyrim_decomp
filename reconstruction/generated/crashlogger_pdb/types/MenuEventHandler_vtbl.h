// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MenuEventHandler_vtbl; size 0x40
#pragma once

struct ButtonEvent;
struct KinectEvent;
struct MotionGestureEvent;
struct MouseMoveEvent;
struct SixaxisEvent;
struct ThumbstickEvent;
struct MenuEventHandler_vtbl {
    void (*_dtor_MenuEventHandler)(void);
    bool (*CanProcess)(char32_t* );
    bool (*ProcessMotionGesture)(MotionGestureEvent* );
    bool (*ProcessSixaxis)(SixaxisEvent* );
    bool (*ProcessKinect)(KinectEvent* );
    bool (*ProcessThumbstick)(ThumbstickEvent* );
    bool (*ProcessMouseMove)(MouseMoveEvent* );
    bool (*ProcessButton)(ButtonEvent* );
};
static_assert(sizeof(MenuEventHandler_vtbl) == 64, "MenuEventHandler_vtbl layout differs from the PDB");
