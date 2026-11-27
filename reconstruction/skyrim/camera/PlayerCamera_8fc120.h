// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: written from the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations; see Adapted bodies
// Adapted bodies: NiPoint3::operator=, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_008e0000_o2.cpp:22380
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// PlayerCamera, sub_14084E150, NiPoint3, x, y, z: CRASHLOGGER_PDB(59818@2026.10.24)
// cameraStates: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FirstPersonState8fc120, g_zeroPoint8fc120, unk00, unk48: GUESS(low)
// 0x8fc120 PlayerCamera::sub_14084E150
#pragma once

#include <cstddef>
#include <cstdint>

struct NiPoint3
{
    NiPoint3() {}
    NiPoint3(const NiPoint3& a_rhs) : x(a_rhs.x), y(a_rhs.y), z(a_rhs.z) {}
    NiPoint3& operator=(const NiPoint3& a_rhs)
    {
        x = a_rhs.x;
        y = a_rhs.y;
        z = a_rhs.z;
        return *this;
    }

    float x;
    float y;
    float z;
};

struct FirstPersonState8fc120
{
    std::uint8_t unk00[0x48];
    NiPoint3 unk48;
};

class PlayerCamera
{
public:
    NiPoint3 sub_14084E150() const;

    std::uint8_t unk00[0xB8];
    FirstPersonState8fc120* cameraStates[13];
};

extern const NiPoint3 g_zeroPoint8fc120;

static_assert(offsetof(PlayerCamera, cameraStates) == 0xB8, "cameraStates offset");
static_assert(offsetof(FirstPersonState8fc120, unk48) == 0x48, "unk48 offset");
