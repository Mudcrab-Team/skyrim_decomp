// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ImageSpaceEffectRefraction, ImageSpaceEffectRefraction::UpdateParams: CRASHLOGGER_PDB(59818@2026.10.24); names only
// ParamOwner, ParamBlock, RefractionSettings, g_refractionSettings, ParamBlock::Function152b170: STANDIN GUESS(low); names made up for the callee at 0x152b170, its owner and a global
// unk30, first, unk98, unk9C, unkA0, unkA4: GUESS(low); offsets from the listing
#pragma once

#include <cstdint>
#include <cstddef>

class ImageSpaceEffectParam;

class ParamBlock
{
public:
    void Function152b170(int a_index, float a_a, float a_b, float a_c, float a_d);  // callee at 0x152b170, not compared
};

struct ParamOwner
{
    ParamBlock* first;  // 00
};

struct RefractionSettings
{
    std::uint8_t unk00[0x98];
    float unk98;   // 98
    float unk9C;   // 9C
    float unkA0;   // A0
    float unkA4;   // A4
};
extern RefractionSettings* g_refractionSettings;

class ImageSpaceEffectRefraction
{
public:
    virtual bool UpdateParams(ImageSpaceEffectParam* a_param);  // compared: 0x1565a20

    std::uint8_t unk08[0x28];
    ParamOwner* unk30;  // 30
};
static_assert(offsetof(ImageSpaceEffectRefraction, unk30) == 0x30, "layout");
