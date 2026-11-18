// BSPCOrbisGamepadDevice, sub, Register, Manager, SetEnabled, configuration, manager: GUESS(low)
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis only).
// 0xe7bf50 BSPCOrbisGamepadDevice::Initialize

#include "BSPCOrbisGamepadDevice.h"
void BSPCOrbisGamepadDevice::sub() { Register(configuration); manager->SetEnabled(true); }
