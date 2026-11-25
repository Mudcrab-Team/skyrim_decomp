// Exposure detail: (community naming and local pinned-image observations).
// Source exposure: mixed
// Code origin: original; no sibling body reused
// SPDX-License-Identifier: CC0-1.0
// NiPSysEmitterCtlr, NiPSysEmitterCtlr::TargetIsRequiredType: CRASHLOGGER_PDB(59818@2026.10.24)
// NiSingleInterpController, NiSingleInterpController::TargetIsRequiredType: OBSERVED
// NiRTTI, NiPSysModifier, ModifierNode, ParticleTarget, their members, NiPSysEmitterType, modifierName: STANDIN GUESS(low)

#pragma once
#include <cstdint>
#include <cstddef>

struct NiRTTI {
    const char* name;
    const NiRTTI* base;
};
extern const NiRTTI NiPSysEmitterType;
class NiPSysModifier {
public:
    virtual void Unk00();
    virtual void Unk08();
    virtual const NiRTTI* GetRTTI();
    std::uint8_t pad08[8];
    const char* name;
};
struct ModifierNode {
    ModifierNode* next;
    ModifierNode* previous;
    NiPSysModifier* modifier;
};
struct ParticleTarget {
    std::uint8_t pad00[0x168];
    ModifierNode* modifiers;
};
class NiSingleInterpController {
public:
    bool TargetIsRequiredType();
    std::uint8_t pad00[0x38];
    ParticleTarget* target;
};
class NiPSysEmitterCtlr : public NiSingleInterpController {
public:
    bool TargetIsRequiredType();
    std::uint8_t pad40[0x10];
    const char* modifierName;
};
static_assert(offsetof(NiPSysModifier, name) == 0x10, "modifier name offset");
static_assert(offsetof(NiPSysEmitterCtlr, modifierName) == 0x50, "controller name offset");
