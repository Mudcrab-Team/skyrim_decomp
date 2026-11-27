// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sun::GetLightValue: GUESS(low); the name comes from the inventory (Function41b230), a made-up name for what the function returns
// Sun, SunParent, SunNode, LightNode, TypeInfo, kLightType, GetRTTI, unk30, unk128, unk94: STANDIN GUESS(low); only what the function reads; GetRTTI is virtual slot 02 of the node
#pragma once

#include <cstdint>
#include <cstddef>

struct TypeInfo;
extern const TypeInfo kLightType;

class SunNode
{
public:
    virtual ~SunNode();
    virtual void Slot01();
    virtual const TypeInfo* GetRTTI();  // 02
};

class LightNode : public SunNode
{
public:
    std::uint8_t unk08[0x8c];
    float unk94;  // 94
};

struct SunParent
{
    std::uint8_t unk00[0x128];
    SunNode* unk128;  // 128
};

class Sun
{
public:
    float Function41b230();  // compared: 0x41b230

    std::uint8_t unk00[0x30];
    SunParent* unk30;  // 30
};
static_assert(offsetof(Sun, unk30) == 0x30, "layout");
