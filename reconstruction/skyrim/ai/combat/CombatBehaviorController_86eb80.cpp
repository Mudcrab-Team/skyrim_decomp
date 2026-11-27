// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x86eb80 CombatBehaviorController::GetCurrentCombatInventory
// Adapted bodies: none
#include "CombatBehaviorController_86eb80.h"

// Return the combat inventory for the thread-local active behavior thread.
CombatInventory* CombatBehaviorController::GetCurrentCombatInventory()
{
    return g_currentThread_tls_0x6a0->controller->combatController->combatInventory;
}
