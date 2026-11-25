// Source exposure: mixed (community declarations, the cited sibling and the pinned image listing).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: ImageSpaceModifierInstanceDOF::PrintInfo follows momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/imagespacemodifierinstance.cpp
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/imagespacemodifierinstance.cpp:465
// ImageSpaceModifierInstanceDOF, ImageSpaceModifierInstanceDOF::PrintInfo, ImageSpaceModifierInstanceTemp, ImageSpaceModifierInstance, strength, kDOFDistance, kDOFRange: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ImageSpaceModifierInstance, ImageSpaceModifierInstanceTemp: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// distance, range: GUESS(low); named after the sibling's fields and the DOF slots of the community mod data
// sprintf_s: CRASHLOGGER_PDB(59818@2026.10.24)
// unk08, unk18, unk20, unk24, unk28, unk30: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

extern "C" int sprintf_s(char* buffer, std::size_t size, const char* format, ...);

class ImageSpaceModifierInstance
{
public:
    virtual ~ImageSpaceModifierInstance();
    virtual bool Unk_25();                   // 25
    virtual void Apply() = 0;                // 26
    virtual void* IsForm();                  // 27
    virtual void PrintInfo(char* a_dstBuf) = 0;  // 28

    std::uint64_t unk08;
    std::uint32_t unk10;
    float strength;  // 14
    std::uint64_t unk18;
    float unk20;
    std::uint32_t unk24;
};
static_assert(sizeof(ImageSpaceModifierInstance) == 0x28, "base size");

class ImageSpaceModifierInstanceTemp : public ImageSpaceModifierInstance
{
public:
    std::uint64_t unk28;
};
static_assert(sizeof(ImageSpaceModifierInstanceTemp) == 0x30, "temporary instance size");

class ImageSpaceModifierInstanceDOF : public ImageSpaceModifierInstanceTemp
{
public:
    void PrintInfo(char* a_dstBuf) override;  // 28

    float unk30[14];
    float distance;  // 68, ImageSpaceModData slot kDOFDistance
    float range;     // 6C, ImageSpaceModData slot kDOFRange
    float unk70[2];
};
static_assert(sizeof(ImageSpaceModifierInstanceDOF) == 0x78, "DOF instance size");
