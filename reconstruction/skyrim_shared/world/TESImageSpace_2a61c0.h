// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from the pinned image listing; community names and offsets as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESImageSpace, TESImageSpace::InitializeData, TESImageSpace::data, ImageSpaceBaseData, ImageSpaceBaseData::HDR, ImageSpaceBaseData::Cinematic, ImageSpaceBaseData::Tint, ImageSpaceBaseData::DepthOfField: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ImageSpaceBaseData::DepthOfField::flags, ImageSpaceBaseData::DepthOfField::skyBlurRadius: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG's enumeration is a plain 16-bit value here
// TESForm, TESForm::formType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the vtable slots up to InitializeData and the members up to 0x20; its constructor is the callee at 0x1e3020
// ImageSpaceBaseData constructor: GUESS(low); the member constructor at 0x1536a40, not compared here
// kFormType: GUESS(low); the form type byte 0x59 is stored by the constructor
#pragma once

#include <cstdint>
#include <cstddef>

struct ImageSpaceBaseData
{
    struct HDR
    {
        float eyeAdaptSpeed;          // 00
        float bloomBlurRadius;        // 04
        float bloomThreshold;         // 08
        float bloomScale;             // 0C
        float receiveBloomThreshold;  // 10
        float white;                  // 14
        float sunlightScale;          // 18
        float skyScale;               // 1C
        float eyeAdaptStrength;       // 20
    };
    struct Cinematic
    {
        float saturation;  // 0
        float brightness;  // 4
        float contrast;    // 8
    };
    struct Tint
    {
        struct ColorF
        {
            float red;    // 0
            float green;  // 4
            float blue;   // 8
        };
        float amount;  // 00
        ColorF color;  // 04
    };
    struct DepthOfField
    {
        float strength;                // 00
        float distance;                // 04
        float range;                   // 08
        std::uint16_t flags;           // 0C
        std::uint16_t skyBlurRadius;   // 0E
    };

    ImageSpaceBaseData();  // callee at 0x1536a40, not compared here

    HDR hdr;                    // 00
    Cinematic cinematic;        // 24
    Tint tint;                  // 30
    DepthOfField depthOfField;  // 40
};
static_assert(sizeof(ImageSpaceBaseData) == 0x50, "ImageSpaceBaseData size");

class TESForm
{
public:
    TESForm();  // callee at 0x1e3020, not compared here
    virtual ~TESForm();
    virtual void Init();                  // 01
    virtual void ReleaseManagedData();    // 02
    virtual void ClearData();             // 03
    virtual void InitializeData();        // 04

    std::uint8_t unk08[0x8];
    std::uint32_t formFlags;      // 10
    std::uint32_t formID;         // 14
    std::uint16_t inGameFormFlags; // 18
    std::uint8_t formType;        // 1A
    std::uint8_t unk1B[5];
};
static_assert(sizeof(TESForm) == 0x20, "TESForm size");

class TESImageSpace : public TESForm
{
public:
    TESImageSpace();  // compared: 0x2a61c0
    ~TESImageSpace() override;
    void InitializeData() override;

    ImageSpaceBaseData data;  // 20
};
static_assert(sizeof(TESImageSpace) == 0x70, "TESImageSpace size");
