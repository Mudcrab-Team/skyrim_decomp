// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// BaseForm290e50, Bounds290e50, ExtraList290e50, Ref290e50, Obj290e50: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern float g_radiusThreshold290e50;

struct BaseForm290e50
{
    float GetRadius() const;

    std::uint8_t unk00[0x1A];  // 0x00
    std::uint8_t formType;     // 0x1A
    std::uint8_t unk1B[0x6D];  // 0x1B
    std::uint8_t flags88;      // 0x88
};

struct Bounds290e50
{
    std::uint8_t unk00[0x0C];  // 0x00
    float x;                   // 0x0C
    float y;                   // 0x10
    float z;                   // 0x14
};

struct ExtraList290e50
{
    const Bounds290e50* GetBounds() const;
};

struct Ref290e50
{
    float GetScale() const;

    std::uint8_t unk00[0x40];      // 0x00
    const BaseForm290e50* base40;  // 0x40
    std::uint8_t unk48[0x28];      // 0x48
    ExtraList290e50 extraList70;   // 0x70
};

class Obj290e50
{
public:
    static bool Function290e50(const Ref290e50* a_ref);
};

static_assert(offsetof(BaseForm290e50, formType) == 0x1A, "formType offset");
static_assert(offsetof(BaseForm290e50, flags88) == 0x88, "flags88 offset");
static_assert(offsetof(Bounds290e50, x) == 0x0C, "x offset");
static_assert(offsetof(Ref290e50, base40) == 0x40, "base40 offset");
static_assert(offsetof(Ref290e50, extraList70) == 0x70, "extraList70 offset");
