// Source exposure: binary-analysis (class names from the image's RTTI; sizes and the inlined destructor body from the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// BSBlendTreadTransfInterpolator, NiBlendTransformInterpolator: EXE_RTTI
// NiBlendInterpolator: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); the base type, only its out-of-line destructor is modelled
#pragma once

class NiBlendInterpolator
{
public:
    NiBlendInterpolator();
    virtual ~NiBlendInterpolator();

    unsigned char unk08[0x40];  // 08
};

class NiBlendTransformInterpolator : public NiBlendInterpolator
{
public:
    NiBlendTransformInterpolator();
};

class BSBlendTreadTransfInterpolator : public NiBlendTransformInterpolator
{
public:
    BSBlendTreadTransfInterpolator();
    ~BSBlendTreadTransfInterpolator() override {}

    unsigned char unk48[0x8];  // 48
};
static_assert(sizeof(BSBlendTreadTransfInterpolator) == 0x50, "size from the deleting destructor");
