// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: written from the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations; see Adapted bodies
// Adapted bodies: NiPoint3::operator=, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_008e0000_o2.cpp:22380
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// PlayerCamera, GetFirstPersonNodePosition_14084B030, NiPoint3, x, y, z: CRASHLOGGER_PDB(59818@2026.10.24)
// PlayerCamera::cameraStates, FirstPersonState::firstPersonCameraObj: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CameraNode8f8c10, FirstPersonState8f8c10, g_zeroPoint8f8c10, unk00, unk58, unkA0: GUESS(low)
// 0x8f8c10 PlayerCamera::GetFirstPersonNodePosition_14084B030
#pragma once

#include <cstddef>
#include <cstdint>

struct NiPoint3
{
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

struct CameraNode8f8c10
{
    std::uint8_t unk00[0xA0];
    NiPoint3 unkA0;
};

struct FirstPersonState8f8c10
{
    std::uint8_t unk00[0x58];
    CameraNode8f8c10* firstPersonCameraObj;
};

class PlayerCamera
{
public:
    void GetFirstPersonNodePosition_14084B030(NiPoint3& a_out) const;

    std::uint8_t unk00[0xB8];
    FirstPersonState8f8c10* cameraStates[13];
};

extern const NiPoint3 g_zeroPoint8f8c10;

static_assert(offsetof(PlayerCamera, cameraStates) == 0xB8, "cameraStates offset");
static_assert(offsetof(FirstPersonState8f8c10, firstPersonCameraObj) == 0x58, "firstPersonCameraObj offset");
static_assert(offsetof(CameraNode8f8c10, unkA0) == 0xA0, "unkA0 offset");
