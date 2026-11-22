// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSTempEffectSPG: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) SYMBOLS(fo4-pdb); renamed from the placeholder class BSTempEffect
// data, spg3D, unk40, unk44, unk48: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTempEffect, TESObjectCELL, BGSShaderParticleGeometryData, NiAVObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

class TESObjectCELL;
class BGSShaderParticleGeometryData;
class NiAVObject;

class BSTempEffect
{
public:
    BSTempEffect(TESObjectCELL* a_cell, float a_lifetime);  // bound: 0x4a9860
    virtual ~BSTempEffect();                                // 00

    unsigned char pad08[0x28];  // 08
};

class BSTempEffectSPG : public BSTempEffect
{
public:
    BSTempEffectSPG();  // compared: 0x4b4bd0
    ~BSTempEffectSPG() override;

    BGSShaderParticleGeometryData* data;  // 30
    NiAVObject* spg3D;                    // 38
    float unk40;                          // 40
    float unk44;                          // 44
    bool unk48;                           // 48
};
