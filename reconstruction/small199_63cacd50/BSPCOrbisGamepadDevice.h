// BSPCOrbisGamepadDevice, sub, Register, Manager, SetEnabled, configuration, manager: GUESS(low)
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis only).

#pragma once
// BSPCOrbisGamepadDevice, sub, Register, Manager, SetEnabled, configuration, manager: GUESS(low)
class Manager { public: void SetEnabled(int); };
extern void* configuration;
extern Manager* manager;
class BSPCOrbisGamepadDevice { public: void sub(); void Register(void*); };
