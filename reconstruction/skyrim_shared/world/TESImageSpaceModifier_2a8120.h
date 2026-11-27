// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESImageSpaceModifier::InitializeData: CRASHLOGGER_PDB(59818@2026.10.24); name only
// ImageSpaceModifierData, ImageSpaceModifierData::MultAdd, ImageSpaceModifierData::MinMax, ImageSpaceModifierData::HDR, ImageSpaceModifierData::Bloom, ImageSpaceModifierData::Cinematic, ImageSpaceModifierData::DOF, ::mult, ::add, ::min, ::max, ::eyeAdaptSpeed, ::bloomBlurRadius, ::bloomThreshold, ::bloomScale, ::targetLum, ::sunlightScale, ::skyScale, ::empty, ::saturation, ::brightness, ::contrast, ::strength, ::distance, ::range, ::useTarget, ::pad0E, ::animatable, ::pad01, ::pad02, ::duration, ::hdr, ::bloom, ::cinematic, ::tintColor, ::blurRadius, ::doubleVisionStrength, ::radialBlurStrength, ::radialBlurRampUp, ::radialBlurStart, ::useTargetForRadialBlur, ::padC9, ::padCA, ::radialBlurCenter, ::dof, ::radialBlurRampDown, ::radialBlurDownStart, ::fadeColor, ::motionBlurStrength, NiPoint2, TESImageSpaceModifier::data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ImageSpaceModifierData::DOF::flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG's mode enumeration is a plain byte value here
// ImageSpaceModifierData::Clear: GUESS(low); an inline reset of the whole block
#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>

struct NiPoint2
{
    float x;
    float y;
};

struct ImageSpaceModifierData
{
    template <class T>
    struct MultAdd
    {
        T mult;
        T add;
    };
    template <class T>
    struct MinMax
    {
        MultAdd<T> min;
        MultAdd<T> max;
    };
    struct HDR
    {
        MultAdd<float> eyeAdaptSpeed;     // 00
        MultAdd<float> bloomBlurRadius;   // 08
        MultAdd<float> bloomThreshold;    // 10
        MultAdd<float> bloomScale;        // 18
        MinMax<float> targetLum;          // 20
        MultAdd<float> sunlightScale;     // 30
        MultAdd<float> skyScale;          // 38
        MultAdd<float> empty[6];          // 40
    };
    struct Bloom
    {
        MultAdd<float> empty[3];          // 00
    };
    struct Cinematic
    {
        MultAdd<float> saturation;        // 00
        MultAdd<float> brightness;        // 08
        MultAdd<float> contrast;          // 10
        MultAdd<float> empty;             // 18
    };
    struct DOF
    {
        std::uint32_t strength;  // 00
        std::uint32_t distance;  // 04
        std::uint32_t range;     // 08
        bool useTarget;          // 0C
        std::uint8_t flags;      // 0D
        std::uint16_t pad0E;     // 0E
    };

    void Clear() { std::memset(this, 0, sizeof(*this)); }

    bool animatable;                     // 00
    std::uint8_t pad01;                  // 01
    std::uint16_t pad02;                 // 02
    float duration;                      // 04
    HDR hdr;                             // 08
    Bloom bloom;                         // 78
    Cinematic cinematic;                 // 90
    std::uint32_t tintColor;             // B0
    std::uint32_t blurRadius;            // B4
    std::uint32_t doubleVisionStrength;  // B8
    std::uint32_t radialBlurStrength;    // BC
    std::uint32_t radialBlurRampUp;      // C0
    std::uint32_t radialBlurStart;       // C4
    bool useTargetForRadialBlur;         // C8
    std::uint8_t padC9;                  // C9
    std::uint16_t padCA;                 // CA
    NiPoint2 radialBlurCenter;           // CC
    DOF dof;                             // D4
    std::uint32_t radialBlurRampDown;    // E4
    std::uint32_t radialBlurDownStart;   // E8
    std::uint32_t fadeColor;             // EC
    std::uint32_t motionBlurStrength;    // F0
};
static_assert(sizeof(ImageSpaceModifierData) == 0xF4, "data size");

class TESImageSpaceModifier
{
public:
    void InitializeData();  // compared: 0x2a8120

    std::uint8_t unk00[0x20];
    ImageSpaceModifierData data;  // 20
};
static_assert(offsetof(TESImageSpaceModifier, data) == 0x20, "data offset");
