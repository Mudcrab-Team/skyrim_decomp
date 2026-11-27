// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// CombatGroup, CombatController, CombatBehaviorThread, CombatBehaviorController, CombatBehaviorController::GetCurrentCombatGroup: CRASHLOGGER_PDB(59818@2026.10.24)
// g_currentThread_tls_0x6a0, CombatController::combatGroup, CombatBehaviorThread::unk00, CombatBehaviorThread::controller, CombatBehaviorController::unk00, CombatBehaviorController::combatController: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class CombatGroup;
class CombatBehaviorController;

class CombatController
{
public:
    CombatGroup* combatGroup;  // 0x00
};

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
    static CombatGroup* GetCurrentCombatGroup();

    std::uint8_t      unk00[0x20];
    CombatController* combatController;  // 0x20
};
static_assert(offsetof(CombatBehaviorController, combatController) == 0x20, "combatController offset");
