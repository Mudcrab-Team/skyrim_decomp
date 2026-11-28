// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiParticleInfo: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPoint3, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ZERO, velocity, age, lifeSpan, lastUpdate, generation, code: GUESS(low) STANDIN
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

class NiParticleInfo
{
public:
    NiParticleInfo();

    NiPoint3      velocity;    // 00
    float         age;         // 0C
    float         lifeSpan;    // 10
    float         lastUpdate;  // 14
    std::uint16_t generation;  // 18
    std::uint16_t code;        // 1A
};
static_assert(sizeof(NiParticleInfo) == 0x1C, "NiParticleInfo size");
