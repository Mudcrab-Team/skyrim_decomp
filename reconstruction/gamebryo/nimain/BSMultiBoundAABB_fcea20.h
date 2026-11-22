// Source exposure: mixed (pinned image and public declarations).
// Code origin: original partial layout for BSMultiBoundAABB construction and sphere test.
// BSMultiBoundAABB, BSMultiBoundShape, NiPoint3, x, y, z, Unk_28: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// unknown18, unk1C, unknown28, unk2C, unknown38: GUESS(low)
#pragma once

#include "BSMultiBoundShape.h"

class NiPoint3
{
public:
    float x;
    float y;
    float z;
};
static_assert(sizeof(NiPoint3) == 0xC, "NiPoint3 size");

class BSMultiBoundAABB : public BSMultiBoundShape
{
public:
    BSMultiBoundAABB();
    virtual std::uint32_t Unk_28(const float* sphere);

    std::uint8_t unknown18[0x4];
    NiPoint3 unk1C;
    std::uint8_t unknown28[0x4];
    NiPoint3 unk2C;
    std::uint8_t unknown38[0x8];
};
static_assert(sizeof(BSMultiBoundAABB) == 0x40, "BSMultiBoundAABB size");
