// Source exposure: mixed (pinned-image observations; community-generated declarations).
// Code origin: original; pinned-image observations and labelled naming sources
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiTimeController, NiTimeController::IsEqual, flags, frequency, Phase_18, LoKeyTime_1C, HiKeyTime_20, Target_38: CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject, NiObject::IsEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiObject layout: STANDIN GUESS(low)
#pragma once
#include <cstdint>
#include <cstddef>
struct NiObject {
    void* vtable;
    std::uint64_t referenceState;
    bool IsEqual(NiObject* other);
};
struct NiTimeController : NiObject {
    std::uint16_t flags;
    float frequency;
    float Phase_18;
    float LoKeyTime_1C;
    float HiKeyTime_20;
    float StartTime_24;
    float lastTime;
    float weightedLastTime;
    float ScaledTime_30;
    std::uint32_t unknown34;
    void* Target_38;
    NiTimeController* NextController_40;
    bool IsEqual(NiObject* other);
};
static_assert(offsetof(NiTimeController, Target_38) == 0x38, "target offset");
