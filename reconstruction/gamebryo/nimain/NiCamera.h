// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// NiCamera: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiCamera::UpdateWorldData, NiCamera::UpdateWorldBound, NiCamera::~NiCamera: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// NiCameraBase: STANDIN GUESS(low); the layout is inferred from the listings, the class name is invented
// BaseUpdateWorldData, UpdateCameraWorldData, the base destructor: GUESS(low); bound by address through bind-hints.json
// worldBoundA, worldBoundB, worldBoundC, worldBoundCopyA, worldBoundCopyB, worldBoundCopyC: GUESS(low); names invented
// unknown110, unk08, unkAC, unkF0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

// NiCameraBase: STANDIN GUESS(low); same 0x110 size as the NiAVObject base, declaring the fields the compared code reads
class NiCameraBase
{
public:
    // NiCameraBase destructor: GUESS(low); declared only, bound by address
    virtual ~NiCameraBase();

    // unk08: GUESS(low); members not recovered
    std::uint8_t unk08[0x98];  // 08
    // worldBoundA..C: GUESS(low); the three dwords the bound update reads
    std::uint32_t worldBoundA;  // A0
    std::uint32_t worldBoundB;  // A4
    std::uint32_t worldBoundC;  // A8
    // unkAC: GUESS(low); members not recovered
    std::uint8_t unkAC[0x38];  // AC
    // worldBoundCopyA..C: GUESS(low); the three dwords the bound update writes
    std::uint32_t worldBoundCopyA;  // E4
    std::uint32_t worldBoundCopyB;  // E8
    std::uint32_t worldBoundCopyC;  // EC
    // unkF0: GUESS(low); padding up to the 0x110 size
    std::uint8_t unkF0[0x20];  // F0
};
static_assert(sizeof(NiCameraBase) == 0x110, "NiCameraBase size");

// NiRTTI-free: the camera's own pieces only
class NiCamera : public NiCameraBase
{
public:
    NiCamera();
    virtual ~NiCamera() {}  // compared: 0xef1a10 (scalar deleting destructor; the listing inlines the teardown)
    virtual void UpdateWorldData();  // compared: 0xef1770
    virtual void UpdateWorldBound();  // compared: 0xef1950

    // BaseUpdateWorldData, UpdateCameraWorldData: GUESS(low); names invented, bound by address
    void BaseUpdateWorldData();
    void UpdateCameraWorldData();

    // unknown110: GUESS(low); members not recovered, sized so the static_assert holds
    std::uint8_t unknown110[0x78];  // 110
};
static_assert(sizeof(NiCamera) == 0x188, "NiCamera size");
