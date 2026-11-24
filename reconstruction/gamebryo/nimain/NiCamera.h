// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: written for this reconstruction from the listing; names and layout from community headers.
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// NiCamera: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiCameraBase: STANDIN GUESS(low); the layout is inferred from the listings, the class name is invented
#pragma once

#include <cstdint>
#include <cstddef>

class NiCameraBase
{
public:
    virtual ~NiCameraBase();

    std::uint8_t unk08[0x98];  // 08
    std::uint32_t worldBoundA;  // A0
    std::uint32_t worldBoundB;  // A4
    std::uint32_t worldBoundC;  // A8
    std::uint8_t unkAC[0x38];  // AC
    std::uint32_t worldBoundCopyA;  // E4
    std::uint32_t worldBoundCopyB;  // E8
    std::uint32_t worldBoundCopyC;  // EC
    std::uint8_t unkF0[0x20];  // F0
};

class NiCamera : public NiCameraBase
{
public:
    NiCamera();
    virtual ~NiCamera() {}  // compared: 0xef1a10
    virtual void UpdateWorldData();  // compared: 0xef1770
    virtual void UpdateWorldBound();  // compared: 0xef1950

    void BaseUpdateWorldData();
    void UpdateCameraWorldData();
    void Functioneefac0();  // compared: 0xeefac0

    std::uint8_t unknown110[0x78];  // 110
};
