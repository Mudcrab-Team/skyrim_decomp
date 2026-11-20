// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBoxBV: EXE_RTTI
// BoxShape, box, LoadBinary, SaveBinary, IsSameVolume, IsEqual, Differs: GUESS(low)
#pragma once

#include "NiBoundingVolume_f25b40.h"

class BoxShape
{
public:
    void LoadBinary(NiStream& stream);
    void SaveBinary(NiStream& stream);
    bool IsEqual(const BoxShape& other) const;
};

class NiBoxBV : public NiBoundingVolume
{
public:
    void LoadBinary(NiStream& stream);
    void SaveBinary(NiStream& stream);
    bool IsSameVolume(const NiBoundingVolume& other) const;
    bool Differs(const NiBoundingVolume& other) const;

private:
    BoxShape box;
};
