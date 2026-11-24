// Source exposure: mixed (CrashLogger layout names; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x80a250 CombatAimController::Function80a250
// Adapted bodies: none
#include "CombatAimController_80a250.h"

constexpr std::uint32_t kFlagUnk0 = 1;

void CombatAimController::Function80a250(const NiPoint3& a_point)
{
    P.x = a_point.x;
    P.y = a_point.y;
    P.z = a_point.z;
    timer = AITimer(gUnk324430c, 0.0f);
    flags.set(kFlagUnk0);
}
