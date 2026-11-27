// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x86eb40 CombatBehaviorController::GetCurrentCombatState
// Adapted bodies: none
#include "CombatBehaviorController_86eb40.h"

// Return the combat state for the thread-local active behavior thread.
CombatState* CombatBehaviorController::GetCurrentCombatState()
{
    return g_currentThread_tls_0x6a0->controller->combatController->combatState;
}
