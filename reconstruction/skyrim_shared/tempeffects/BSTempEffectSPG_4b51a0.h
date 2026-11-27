// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/TempEffects/BSTempEffectSPG.cpp:175
// BSTempEffectSPG, BSTempEffectSPG::LoadGame, BSTempEffectSPG::pSPGData, BSTempEffectSPG::fTotalFadeTime, BSTempEffectSPG::fFadeTime, BSTempEffectSPG::bFadeIn, BSTempEffect, BSTempEffect::LoadGame, BGSLoadGameBuffer::LoadFormID, BGSShaderParticleGeometryData: SIBLING(fo4-private@1b765c70, author-permission); stand-ins reduced to what the body uses
// BGSLoadGameBuffer, BGSLoadGameBuffer::LoadDataEndian, TESForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESForm::LookupByID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSLoadGameBuffer::ReadFormID, unk08, unk38: GUESS(low); the template LoadFormID wraps the out-of-line identifier read the listing calls
#pragma once

#include <cstdint>

class TESForm
{
public:
    virtual ~TESForm();

    static TESForm* LookupByID(std::uint32_t a_formID);
};

class BGSShaderParticleGeometryData : public TESForm
{
};

class BGSLoadGameBuffer
{
public:
    virtual ~BGSLoadGameBuffer();

    void ReadFormID(std::uint32_t& a_formID);

    // Reads a form identifier and resolves it to the requested form type.
    template <class T>
    void LoadFormID(T*& a_out)
    {
        std::uint32_t formID = 0;
        ReadFormID(formID);
        a_out = dynamic_cast<T*>(TESForm::LookupByID(formID));
    }
    void LoadDataEndian(void* a_data, std::uint32_t a_offset, std::uint32_t a_size);
};

class BSTempEffect
{
public:
    virtual ~BSTempEffect();
    virtual void LoadGame(BGSLoadGameBuffer* apLoadGameBuffer);

    std::uint8_t unk08[0x28];
};
static_assert(sizeof(BSTempEffect) == 0x30, "BSTempEffect size");

class BSTempEffectSPG : public BSTempEffect
{
public:
    void LoadGame(BGSLoadGameBuffer* apLoadGameBuffer) override;

    BGSShaderParticleGeometryData* pSPGData;  // 30
    std::uint8_t                   unk38[8];  // 38
    float                          fTotalFadeTime;  // 40
    float                          fFadeTime;       // 44
    bool                           bFadeIn;         // 48
};
