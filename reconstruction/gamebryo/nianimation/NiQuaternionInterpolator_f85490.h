// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiQuaternionInterpolator: EXE_RTTI
// NiRotData: STANDIN EXE_RTTI
// value, data, lastIndex, CopyMembers, NiQuaternion::LoadBinary, gDefaultPose: GUESS(low)
// NiQuaternion, w, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiQuaternionInterpolator::LoadBinary: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
#pragma once

#include "NiKeyBasedInterpolator_f6e600.h"

class NiRotData : public NiObject
{
};

struct NiQuaternion
{
    void LoadBinary(NiStream& stream);

    float w;
    float x;
    float y;
    float z;
};

class NiQuaternionInterpolator : public NiKeyBasedInterpolator
{
public:
    void CopyMembers(NiQuaternionInterpolator* dest) const;
    void LoadBinary(NiStream& stream) override;
    NiQuaternionInterpolator(NiRotData* keys);

private:
    NiQuaternion value;
    InterpolatorKeyDataPointer<NiRotData> data;
    std::uint32_t lastIndex;
};
