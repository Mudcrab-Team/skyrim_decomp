// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x86ec00 CombatBehaviorController::GetCurrentCombatController
// Adapted bodies: none
#include "CombatBehaviorController_86ec00.h"

// Return the combat controller owning the thread-local active behavior thread.
CombatController* CombatBehaviorController::GetCurrentCombatController()
{
    return g_currentThread_tls_0x6a0->controller->combatController;
}
