// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiHalfSpaceBV: EXE_RTTI
// HalfSpacePlane, HalfSpacePoint, coefficients, coordinates, plane, point, ComparePlane, IsSamePlane, LoadBinary, SaveBinary, Differs: GUESS(low)
#pragma once

#include "NiBoundingVolume_f25b40.h"

class HalfSpacePlane
{
public:
    void LoadBinary(NiStream& stream);
    void SaveBinary(NiStream& stream);

private:
    float coefficients[4];
};

class HalfSpacePoint
{
public:
    void LoadBinary(NiStream& stream);
    void SaveBinary(NiStream& stream);

private:
    float coordinates[3];
};

class NiHalfSpaceBV : public NiBoundingVolume
{
public:
    bool ComparePlane(const HalfSpacePlane& other) const;
    void LoadBinary(NiStream& stream);
    void SaveBinary(NiStream& stream);
    bool IsSamePlane(const NiHalfSpaceBV& other) const;
    bool Differs(const NiBoundingVolume& other) const;

private:
    HalfSpacePlane plane;
    HalfSpacePoint point;
};
