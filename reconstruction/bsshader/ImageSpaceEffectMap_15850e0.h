// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ImageSpaceEffectMap, ImageSpaceEffectMap::UpdateParams: CRASHLOGGER_PDB(59818@2026.10.24); names only
// ParamBlock, ParamOwner, TextureSlot, TextureRef, Texture and their callees and members: STANDIN GUESS(low); names made up for the callees at 0x152b170 and 0x1555030 and for the owners read from the listing
// unk30, unk48, texture: GUESS(low); offsets from the listing
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

class Texture
{
public:
    void Function1555030(int* a_first, int* a_second);  // callee at 0x1555030, not compared
};

struct TextureSlot
{
    std::uint8_t unk00[8];
    Texture* texture;  // 08
};

class ImageSpaceEffectMap
{
public:
    virtual bool UpdateParams(ImageSpaceEffectParam* a_param);  // compared: 0x15850e0

    std::uint8_t unk08[0x28];
    ParamOwner* unk30;     // 30
    std::uint8_t unk38[0x10];
    TextureSlot* unk48;    // 48
};
static_assert(offsetof(ImageSpaceEffectMap, unk48) == 0x48, "layout");
