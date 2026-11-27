// BSDismemberSkinInstance, unk98, BSShaderProperty, lightData, BSShaderPropertyLightData, activeLightMask: CRASHLOGGER_PDB(59818@2026.10.24)
// skinInstance, rendererData, particleShaderDynamicTriShape: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: none.
// BSShaderAccumulator, AccumulateObject, BSGeometry, renderMode, flagOverrideMode, flagOverrideMask: CRASHLOGGER_PDB(59818@2026.10.24)
// dismemberType, dispatchTable: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
#pragma once

#include "declarations/NiAVObject.h"

struct BSShaderPropertyLightData
{
    unsigned char unknown00[0x1c];
    unsigned activeLightMask;
};
struct BSShaderProperty
{
    unsigned char unknown00[0x70];
    BSShaderPropertyLightData* lightData;
};
class BSDismemberSkinInstance : public NiObject
{
public:
    unsigned char unknown10[0x88];
    bool unk98;
};
class BSGeometry : public NiAVObject
{
public:
    unsigned char unknown110[0x18];
    BSShaderProperty* property;
    NiObject* skinInstance;
    void* rendererData;
    unsigned char unknown140[0x10];
    unsigned char type;
};
class BSShaderAccumulator
{
public:
    bool AccumulateObject(BSGeometry* geometry, unsigned long long argument);
    unsigned char unknown00[0x150];
    int renderMode;
    unsigned char unknown154[0xc];
    unsigned flagOverrideMode;
    unsigned flagOverrideMask;
};

extern const NiRTTI dismemberType;
using Dispatch = bool (*)(BSShaderAccumulator*, BSGeometry*, BSShaderProperty*, unsigned long long);
extern Dispatch dispatchTable[];
