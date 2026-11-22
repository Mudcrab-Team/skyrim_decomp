// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// Code origin: declarations written for this reconstruction; names from the community headers below.
// Adapted bodies: NiPoint3::operator= (CharmedBaryon/CommonLibSSE-NG@b93280e
// src/RE/N/NiPoint3.cpp, MIT; component-wise copy, notice in the SPDX line below).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// BSShadowDirectionalLight: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) EXE_RTTI
// BSLight, BSShadowLight: STANDIN EXE_RTTI
// BSShadowDirectionalLight::GetPassExtraParam: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// unknown10, unknown140, unknown578: GUESS(low)
// NiPoint3, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
// targetDirection, fromDirection, blendTimer, cameraMoved, UpdateSunDirectionBlend: GUESS(low)
// bDisableShadowJumps, fSunShadowUpdateTime, g_realDeltaTime, g_sunDirectionCosThreshold: GUESS(low)
#pragma once

#include <cstdint>
#include "gamebryo/nimain/NiRefObject.h"

struct NiPoint3
{
    float x;
    float y;
    float z;
    NiPoint3& operator=(const NiPoint3& a_other)
    {
        x = a_other.x;
        y = a_other.y;
        z = a_other.z;
        return *this;
    }
    float Unitize();  // normalises in place, returns the old length
};

// ArrayStorage, ArraySize, ShadowArray, FreeArrayStorage: GUESS(low); a stand-in for a dynamic array modelled as its
// allocator part (data pointer and capacity) and its size part at offset 0x10, each with an empty out-of-line destructor
struct ArrayStorage
{
    ~ArrayStorage();
    void* data;  // 00
    std::uint32_t capacity;  // 08
    std::uint32_t pad0C;  // 0C
};

struct ArraySize
{
    ~ArraySize();
    std::uint32_t size;  // 00
    std::uint32_t pad04;  // 04
};

struct ShadowArray : public ArrayStorage, public ArraySize
{
    ~ShadowArray();
};

void FreeArrayStorage(ShadowArray* a_array);

class BSLight : public NiRefObject
{
public:
    std::uint8_t unknown10[0x130];  // 10
};
static_assert(sizeof(BSLight) == 0x140, "BSLight size");

class BSShadowLight : public BSLight
{
public:
    std::uint8_t unknown140[0x420];  // 140
};
static_assert(sizeof(BSShadowLight) == 0x560, "BSShadowLight size");

class BSShadowDirectionalLight : public BSShadowLight
{
public:
    virtual std::uint32_t GetPassExtraParam(std::uint32_t a_accumFlag);  // compared: 0x157ed10
    // GetIsFrustumOrDirectionalLight, GetIsDirectionalLight, GetNeedsClipPlanes: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); each returns true
    virtual bool GetIsFrustumOrDirectionalLight();
    virtual bool GetIsDirectionalLight();
    virtual bool GetNeedsClipPlanes();

    // Blends the sun direction towards a new target over fSunShadowUpdateTime seconds.
    void UpdateSunDirectionBlend(NiPoint3* a_direction, std::int32_t a_previousCameraMoved);

    NiPoint3 targetDirection;       // 560
    NiPoint3 fromDirection;         // 56C
    std::uint8_t unknown578[0x38];  // 578
    float blendTimer;               // 5B0
    std::uint32_t cameraMoved;      // 5B4
};
static_assert(sizeof(BSShadowDirectionalLight) == 0x5B8, "BSShadowDirectionalLight size");
