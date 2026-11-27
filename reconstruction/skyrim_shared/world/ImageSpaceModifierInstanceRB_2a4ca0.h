// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ImageSpaceModifierInstanceRB, ImageSpaceModifierInstanceRB::ctor, ImageSpaceModifierInstanceTemp: CRASHLOGGER_PDB(59818@2026.10.24); names only
// ImageSpaceModifierInstanceTemp: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); size 0x30 and an out-of-line constructor, the callee at 0x2a4630
// NiAVObject, WorldPosition, WorldPosition::Function14eed20, Vec2 and the members of the RB class: STANDIN GUESS(low); names made up from the offsets and callees in the listing
#pragma once

#include <cstdint>
#include <cstddef>

struct Vec2
{
    float x;
    float y;
};

struct WorldPosition
{
    void Function14eed20(Vec2* a_out);  // callee at 0x14eed20, not compared here
    std::uint8_t unk00[0x10];
};

struct NiAVObject
{
    std::uint8_t unk00[0xe4];
    WorldPosition position;  // E4
};

class ImageSpaceModifierInstanceTemp
{
public:
    ImageSpaceModifierInstanceTemp(float a_age, float a_strength, NiAVObject* a_target, float a_duration);  // callee at 0x2a4630, not compared here
    virtual ~ImageSpaceModifierInstanceTemp();
    virtual void Apply();
    virtual void PrintInfo(char* a_dstBuf);

    std::uint8_t unk08[0x28];
};
static_assert(sizeof(ImageSpaceModifierInstanceTemp) == 0x30, "Temp size");

class ImageSpaceModifierInstanceRB : public ImageSpaceModifierInstanceTemp
{
public:
    ImageSpaceModifierInstanceRB(float a_first, float a_second, NiAVObject* a_target, float a_duration,
        float a_x, float a_y, float a_z, float a_w, const float* a_pair);  // compared: 0x2a4ca0
    ~ImageSpaceModifierInstanceRB() override;
    void Apply() override;
    void PrintInfo(char* a_dstBuf) override;

    void* unk30;   // 30
    void* unk38;   // 38
    void* unk40;   // 40
    float unk48;   // 48
    float unk4C;   // 4C
    float unk50;   // 50
    float unk54;   // 54
    float unk58;   // 58
    float unk5C;   // 5C
    float unk60;   // 60
    void* unk68;   // 68
    void* unk70;   // 70
};
static_assert(sizeof(ImageSpaceModifierInstanceRB) == 0x78, "RB size");
