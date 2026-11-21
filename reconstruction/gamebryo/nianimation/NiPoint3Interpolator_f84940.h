// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPoint3Interpolator: EXE_RTTI
// NiPosData: STANDIN EXE_RTTI
// value, data, lastIndex, CopyMembers, NiPoint3::LoadBinary, gDefaultPose: GUESS(low)
// NiPoint3Interpolator::LoadBinary: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// NiPoint3, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include "NiKeyBasedInterpolator_f6e600.h"

class NiPosData : public NiObject
{
};

struct NiPoint3
{
    void LoadBinary(NiStream& stream);

    float x;
    float y;
    float z;
};

class NiPoint3Interpolator : public NiKeyBasedInterpolator
{
public:
    void CopyMembers(NiPoint3Interpolator* dest) const;
    void LoadBinary(NiStream& stream) override;
    NiPoint3Interpolator(NiPosData* keys);

private:
    NiPoint3 value;
    InterpolatorKeyDataPointer<NiPosData> data;
    std::uint32_t lastIndex;
};
