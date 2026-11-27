// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x86ebc0 CombatBehaviorController::GetCurrentCombatGroup
// Adapted bodies: none
#include "CombatBehaviorController_86ebc0.h"

// Return the combat group for the thread-local active behavior thread.
CombatGroup* CombatBehaviorController::GetCurrentCombatGroup()
{
    return g_currentThread_tls_0x6a0->controller->combatController->combatGroup;
}
