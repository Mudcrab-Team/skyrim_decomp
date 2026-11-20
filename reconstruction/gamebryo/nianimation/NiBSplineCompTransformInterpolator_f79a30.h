// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial spline value and parameter layout follows the pinned accesses.
// NiBSplineCompTransformInterpolator: EXE_RTTI
// LoadBinary, SaveBinary, IsEqual: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// CopyMembers, compressionParameters, value, channelHandle, padding: GUESS(low)
#pragma once

#include "NiBSplineInterpolator.h"

// NiBSplineTransformInterpolator: STANDIN EXE_RTTI
class NiBSplineTransformInterpolator : public NiBSplineInterpolator
{
public:
    NiBSplineTransformInterpolator();
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    bool IsEqual(NiObject* other) override;
    void CopyMembers(NiBSplineTransformInterpolator* dest, NiCloningProcess& cloning);

private:
    std::uint8_t padding30[0x30];
};
static_assert(sizeof(NiBSplineTransformInterpolator) == 0x60, "uncompressed parent size");

class NiBSplineCompTransformInterpolator : public NiBSplineTransformInterpolator
{
public:
    NiBSplineCompTransformInterpolator();
    void CopyMembers(NiBSplineCompTransformInterpolator* dest, NiCloningProcess& cloning);
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    bool IsEqual(NiObject* other) override;
    ~NiBSplineCompTransformInterpolator() override = default;

private:
    float compressionParameters[6];
};
static_assert(sizeof(NiBSplineCompTransformInterpolator) == 0x78, "interpolator size");
