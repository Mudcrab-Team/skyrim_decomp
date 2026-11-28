// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// NiRTTI274ae0, Color274ae0, ShaderProp274ae0, Obj274ae0, Obj274ae0::Function274ae0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Color274ae0
{
    float r;  // 0x00
    float g;  // 0x04
    float b;  // 0x08
};

struct NiRTTI274ae0
{
    const char* name;          // 0x00
    const NiRTTI274ae0* base;  // 0x08
};

class ShaderProp274ae0
{
public:
    virtual void VFunc00();
    virtual void VFunc08();
    virtual const NiRTTI274ae0* GetRTTI() const;

    std::uint8_t unk08[0xE8];  // 0x008
    Color274ae0* colorF0;      // 0x0F0
};

extern const NiRTTI274ae0 g_shaderRtti274ae0;
extern Color274ae0 g_defaultColor274ae0;

class Obj274ae0
{
public:
    virtual void VFunc00();
    virtual void VFunc08();
    virtual void VFunc10();
    virtual Obj274ae0* AsNode();
    virtual void VFunc20();
    virtual void VFunc28();
    virtual void VFunc30();
    virtual Obj274ae0* AsGeometry();

    void Function274ae0();

    std::uint8_t unk08[0x110];     // 0x008
    Obj274ae0** children;          // 0x118
    std::uint16_t unk120;          // 0x120
    std::uint16_t childCount;      // 0x122
    std::uint32_t unk124;          // 0x124
    ShaderProp274ae0* shaderProp;  // 0x128
};

static_assert(offsetof(ShaderProp274ae0, colorF0) == 0xF0, "colorF0 offset");
static_assert(offsetof(Obj274ae0, children) == 0x118, "children offset");
static_assert(offsetof(Obj274ae0, childCount) == 0x122, "childCount offset");
static_assert(offsetof(Obj274ae0, shaderProp) == 0x128, "shaderProp offset");
