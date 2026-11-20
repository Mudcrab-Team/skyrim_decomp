// Source exposure: mixed (pinned image listings, project TESGrass layout and community declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial TESGrass declaration adapted from the existing project unit and CommonLibSSE-NG.
// TESGrass, GRASS_DATA, data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetPositionRange, SetPositionRange, SetHeightRange, SetColorRange: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetWavePeriod, GetVertexLighting, SetVertexLighting, SetUniformScaling, SetFitToSlope: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Flag, kVertexLighting, kUniformScale, kFitSlope: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// positionRange, heightRange, colorRange, wavePeriod, flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unrepresentedBase, unrepresentedData: STANDIN GUESS(low)
#pragma once

#include <cstdint>

// Partial declaration covering only the methods and data used by this unit.
class TESGrass
{
public:
    virtual float GetPositionRange() const;
    virtual bool SetPositionRange(float a_positionRange);
    virtual bool SetHeightRange(float a_heightRange);
    virtual bool SetColorRange(float a_colorRange);
    virtual float GetWavePeriod() const;
    virtual bool GetVertexLighting() const;
    virtual void SetVertexLighting(bool a_set);
    virtual void SetUniformScaling(bool a_set);
    virtual void SetFitToSlope(bool a_set);

private:
    struct GRASS_DATA
    {
        enum Flag : std::uint8_t
        {
            kVertexLighting = 1,
            kUniformScale = 2,
            kFitSlope = 4
        };

        std::uint8_t unrepresentedData[0x0C];
        float positionRange;
        float heightRange;
        float colorRange;
        float wavePeriod;
        std::uint8_t flags;
    };
    static_assert(sizeof(GRASS_DATA) == 0x20, "grass data layout");

    std::uint8_t unrepresentedBase[0x50];
    GRASS_DATA data;
};
static_assert(sizeof(TESGrass) == 0x78, "grass form layout");
