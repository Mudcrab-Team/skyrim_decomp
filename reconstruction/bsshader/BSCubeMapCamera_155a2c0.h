// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Cookbook: 0x155a2c0 29
// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the pinned image.
// BSCubeMapCamera, NiCamera, NiPointer, NiRefObject, BSShaderAccumulator, scenes, accumulator, secondAccumulator, unk1B0, silhouetteColor: CRASHLOGGER_PDB(59818@2026.10.24)
// red, green, blue, alpha: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTArray, NiAVObject, NiColorA: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include "gamebryo/nimain/NiCamera_eef3f0.h"

class BSShaderAccumulator : public NiRefObject {};

template <class T>
class BSTArray
{
public:
    ~BSTArray();

private:
    alignas(void*) unsigned char storage[0x18];
};

struct NiColorA
{
    float red;
    float green;
    float blue;
    float alpha;
};

class BSCubeMapCamera : public NiCamera
{
public:
    ~BSCubeMapCamera() override;

    BSTArray<NiPointer<NiAVObject>> scenes;
    NiPointer<BSShaderAccumulator> accumulator;
    NiPointer<BSShaderAccumulator> secondAccumulator;
    NiPointer<NiCamera> unk1B0;
    NiColorA silhouetteColor;
};
static_assert(sizeof(BSCubeMapCamera) == 0x1c8, "cube map camera size");
