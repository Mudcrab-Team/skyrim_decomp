// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiColorInterpolator: EXE_RTTI
// NiColorData: STANDIN EXE_RTTI
// CopyMembers, SetPoseValue, NiColorA::LoadBinary, NiColorA::SaveBinary, gDefaultPose: GUESS(low)
// NiColorInterpolator::LoadBinary, NiColorInterpolator::SaveBinary: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiColorA, red, green, blue, alpha: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiColorInterpolator::colorValue, ::colorData, ::lastIndex: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include "NiKeyBasedInterpolator_f6e600.h"

class NiColorData : public NiObject
{
};

struct NiColorA
{
    void LoadBinary(NiStream& stream);
    void SaveBinary(NiStream& stream) const;

    float red;
    float green;
    float blue;
    float alpha;
};

class NiColorInterpolator : public NiKeyBasedInterpolator
{
public:
    void CopyMembers(NiColorInterpolator* dest) const;
    void LoadBinary(NiStream& stream) override;
    bool RegisterStreamables(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    NiColorInterpolator(NiColorData* keys);
    void SetPoseValue(const NiColorA& pose);

private:
    NiColorA colorValue;
    InterpolatorKeyDataPointer<NiColorData> colorData;
    std::uint32_t lastIndex;
};
