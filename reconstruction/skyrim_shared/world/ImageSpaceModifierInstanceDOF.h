// Source exposure: mixed (community declarations and the contributor-owned pack).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: names and declarations from CharmedBaryon/CommonLibSSE-NG b93280e (MIT); the layout stand-in is written from the listed class sizes
// Adapted bodies: none
// Base form: local stand-ins; the generated base header does not declare the slots the descendants use.
// ImageSpaceModifierInstanceDOF, ImageSpaceModifierInstanceDOF::~ImageSpaceModifierInstanceDOF, ImageSpaceModifierInstanceDOF::Apply, ImageSpaceModifierInstanceDOF::PrintInfo, ImageSpaceModifierInstanceTemp::~ImageSpaceModifierInstanceTemp, ImageSpaceModifierInstanceTemp::Unk_25, ImageSpaceModifierInstanceTemp::PrintInfo: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ImageSpaceModifierInstance, ImageSpaceModifierInstanceTemp: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown08, unknown28, unknown30: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class ImageSpaceModifierInstance
{
public:
    virtual ~ImageSpaceModifierInstance();  // 00
    std::uint64_t unknown08[4];             // 08 .. 27
};
static_assert(sizeof(ImageSpaceModifierInstance) == 0x28, "base size");

class ImageSpaceModifierInstanceTemp : public ImageSpaceModifierInstance
{
public:
    virtual ~ImageSpaceModifierInstanceTemp();  // 00
    virtual bool Unk_25();                      // 25
    virtual void PrintInfo(char* a_dstBuf);     // 28
    std::uint64_t unknown28;                    // 28
};
static_assert(sizeof(ImageSpaceModifierInstanceTemp) == 0x30, "temporary instance size");

class ImageSpaceModifierInstanceDOF : public ImageSpaceModifierInstanceTemp
{
public:
    ImageSpaceModifierInstanceDOF();           // defined so the vftable and its deleting destructor are emitted
    virtual ~ImageSpaceModifierInstanceDOF();  // compared: 0x2a5560; declared but left undefined
    virtual void Apply();                      // 26
    std::uint64_t unknown30[9];                // 30 .. 77
};
static_assert(sizeof(ImageSpaceModifierInstanceDOF) == 0x78, "DOF instance size");
