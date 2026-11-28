// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiParticlesData: CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject, NiPoint3, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ZERO, unk08, unk10, unk11, unk12, boundCenter, boundRadius, unk28..unk88: GUESS(low) STANDIN
#pragma once

#include <cstdint>

class NiPoint3
{
public:
    NiPoint3() {}
    NiPoint3(const NiPoint3& other) : x(other.x), y(other.y), z(other.z) {}

    static const NiPoint3 ZERO;

    float x;  // 00
    float y;  // 04
    float z;  // 08
};
static_assert(sizeof(NiPoint3) == 0xC, "NiPoint3 size");

class NiObject
{
public:
    NiObject();
    virtual ~NiObject();

    std::uint64_t unk08;  // 08
};
static_assert(sizeof(NiObject) == 0x10, "NiObject size");

class NiParticlesData : public NiObject
{
public:
    NiParticlesData();

    bool          unk10;        // 10
    std::uint8_t  unk11;        // 11
    std::uint16_t unk12;        // 12
    NiPoint3      boundCenter;  // 14
    float         boundRadius;  // 20
    std::uint32_t unk24;        // 24
    std::uint64_t unk28;        // 28
    std::uint64_t unk30;        // 30
    std::uint64_t unk38;        // 38
    std::uint64_t unk40;        // 40
    std::uint64_t unk48;        // 48
    std::uint64_t unk50;        // 50
    std::uint64_t unk58;        // 58
    std::uint64_t unk60;        // 60
    std::uint32_t unk68;        // 68
    float         unk6C;        // 6C
    float         unk70;        // 70
    float         unk74;        // 74
    float         unk78;        // 78
    std::uint16_t unk7C;        // 7C
    std::uint16_t unk7E;        // 7E
    std::uint64_t unk80;        // 80
    std::uint16_t unk88;        // 88
};
static_assert(sizeof(NiParticlesData) == 0x90, "NiParticlesData size");
