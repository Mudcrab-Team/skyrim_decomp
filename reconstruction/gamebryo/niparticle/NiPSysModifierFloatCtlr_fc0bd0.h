// Source exposure: mixed (pinned-image observations; community-generated names).
// Code origin: original; pinned-image observations and labelled naming sources
// SPDX-License-Identifier: CC0-1.0
// NiPSysModifierFloatCtlr, NiPSysModifierFloatCtlr::SynchronizePoseInterpolator, NiFloatInterpolator: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRTTI, NiInterpolator, NiFloatInterpolator::SetPoseValue, NiFloatInterpolator_RTTI, GetTargetFloatValue: GUESS(low)
#pragma once
#include <cstdint>
struct NiRTTI {
    const char* name;
    const NiRTTI* parent;
};
struct NiInterpolator;
struct NiInterpolatorVtable {
    void* preceding[2];
    const NiRTTI* (*GetRTTI)(NiInterpolator*);
};
struct NiInterpolator { NiInterpolatorVtable* vtable; };
struct NiFloatInterpolator : NiInterpolator {
    void SetPoseValue(float value);
};
extern const NiRTTI NiFloatInterpolator_RTTI;
struct NiPSysModifierFloatCtlr;
struct NiPSysModifierFloatCtlrVtable {
    void* preceding[62];
    void (*GetTargetFloatValue)(NiPSysModifierFloatCtlr*, float&);
};
struct NiPSysModifierFloatCtlr {
    NiPSysModifierFloatCtlrVtable* vtable;
    void SynchronizePoseInterpolator(NiInterpolator*, std::uint16_t);
};
