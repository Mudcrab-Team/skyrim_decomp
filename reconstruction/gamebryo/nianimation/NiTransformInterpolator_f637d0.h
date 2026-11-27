// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiTransformInterpolator: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); class name only, the class is the placeholder owner
// NiTransformInterpolator::NiTransformInterpolator: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); a constructor taking an initial transform
// NiInterpolator: STANDIN SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); minimal stand-in, layout from the listing
// NiQuatTransform: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); name only, layout from the listing
// scale: STANDIN SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); NiQuatTransform member name
// translate, rotate, NiPoint3, NiQuaternion: GUESS(low); minimal stand-ins, layout from the listing
// transformValue, transformData, unk40, unk44, unk46, pad00: GUESS(low); members at 0x18, 0x38, 0x40, 0x44 and 0x46
#pragma once

#include <cstdint>

struct NiPoint3
{
    float x, y, z;
};

struct NiQuaternion
{
    float w, x, y, z;
};

class NiQuatTransform
{
public:
    NiPoint3 translate;
    NiQuaternion rotate;
    float scale;
};

class NiInterpolator
{
public:
    NiInterpolator();  // 0xf6e9c0

    virtual ~NiInterpolator();

    std::uint8_t pad00[0x10];
};

class NiTransformInterpolator : public NiInterpolator
{
public:
    NiTransformInterpolator(const NiQuatTransform& a_value);  // compared: 0xf637d0

    NiQuatTransform transformValue;
    void* transformData;
    std::uint32_t unk40;
    std::uint16_t unk44;
    std::uint8_t unk46;
};
