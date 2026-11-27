// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// CombatState, CombatController, CombatBehaviorThread, CombatBehaviorController, CombatBehaviorController::GetCurrentCombatState: CRASHLOGGER_PDB(59818@2026.10.24)
// g_currentThread_tls_0x6a0, CombatController::unk00, CombatController::combatState, CombatBehaviorThread::unk00, CombatBehaviorThread::controller, CombatBehaviorController::unk00, CombatBehaviorController::combatController: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class CombatState;
class CombatBehaviorController;

class CombatController
{
public:
    std::uint64_t unk00;
    CombatState*  combatState;  // 0x08
};
static_assert(offsetof(CombatController, combatState) == 0x08, "CombatController::combatState offset");

class CombatBehaviorThread
{
public:
    std::uint8_t              unk00[0x158];
    CombatBehaviorController* controller;  // 0x158
};
static_assert(offsetof(CombatBehaviorThread, controller) == 0x158, "CombatBehaviorThread::controller offset");

extern __declspec(thread) CombatBehaviorThread* g_currentThread_tls_0x6a0;

class CombatBehaviorController
{
public:
    static CombatState* GetCurrentCombatState();

    std::uint8_t      unk00[0x20];
    CombatController* combatController;  // 0x20
};
static_assert(offsetof(CombatBehaviorController, combatController) == 0x20, "combatController offset");
