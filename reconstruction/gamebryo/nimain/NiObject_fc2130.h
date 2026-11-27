// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiObject, NiPoint3: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject::unk08, NiPoint3::x, NiPoint3::y, NiPoint3::z, g_defaultOrigin, Functionfc2130Object, Functionfc2130Object::unk10, Functionfc2130Object::unk14, Functionfc2130Object::unk15, Functionfc2130Object::unk18, Functionfc2130Object::origin, Functionfc2130Object::unk2C, Functionfc2130Object::unk30, Functionfc2130Object::unk38: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiObject
{
public:
    NiObject();
    virtual ~NiObject();

    std::uint8_t unk08[0x08];
};
static_assert(sizeof(NiObject) == 0x10, "NiObject size");

struct NiPoint3
{
    NiPoint3() = default;
    NiPoint3(const NiPoint3& a_rhs) : x(a_rhs.x), y(a_rhs.y), z(a_rhs.z) {}

    float x;
    float y;
    float z;
};
static_assert(sizeof(NiPoint3) == 0x0C, "NiPoint3 size");

extern const NiPoint3 g_defaultOrigin;

class Functionfc2130Object : public NiObject
{
public:
    Functionfc2130Object(float a_value, bool a_flag1, bool a_flag2, void* a_ptr);

    float unk10;
    bool unk14;
    bool unk15;
    void* unk18;
    NiPoint3 origin;
    std::uint32_t unk2C;
    std::uint64_t unk30;
    std::uint64_t unk38;
};
static_assert(offsetof(Functionfc2130Object, unk10) == 0x10, "unk10 offset");
static_assert(offsetof(Functionfc2130Object, unk18) == 0x18, "unk18 offset");
static_assert(offsetof(Functionfc2130Object, origin) == 0x20, "origin offset");
static_assert(offsetof(Functionfc2130Object, unk38) == 0x38, "unk38 offset");
