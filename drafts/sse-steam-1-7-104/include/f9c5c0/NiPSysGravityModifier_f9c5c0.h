// Exposure detail: (community-generated layouts; pinned-image observations).
// Source exposure: mixed
// Code origin: original; labelled declarations and pinned-image observations
// NiPSysGravityModifier, NiPSysModifier, gravityObj, gravityAxis, decay, strength, forceType, turbulence, scale, worldAligned: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPoint3: CRASHLOGGER_PDB(59818@2026.10.24)
// NiObjectVTable, NiObjectRef: STANDIN OBSERVED
// NiPSysModifier::IsEqual, NiPSysGravityModifier::IsEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once
#include <cstdint>
#include <cstddef>

struct NiObjectRef;
struct NiObjectVTable
{
    void* precedingSlots[28];
    bool (*isEqual)(NiObjectRef*, NiObjectRef*);
};
struct NiObjectRef
{
    NiObjectVTable* vtable;
    std::uint32_t refCount;
};
class NiPSysModifier : public NiObjectRef
{
public:
    bool IsEqual(NiObjectRef* other);
    const char* name;
    std::uint32_t order;
    void* target;
    bool active;
};
struct NiPoint3 { float x, y, z; };
class NiPSysGravityModifier : public NiPSysModifier
{
public:
    bool IsEqual(NiObjectRef* other);
    NiObjectRef* gravityObj;
    NiPoint3 gravityAxis;
    float decay;
    float strength;
    std::uint32_t forceType;
    float turbulence;
    float scale;
    bool worldAligned;
};
static_assert(offsetof(NiPSysGravityModifier, gravityObj) == 0x30, "gravity object offset");
