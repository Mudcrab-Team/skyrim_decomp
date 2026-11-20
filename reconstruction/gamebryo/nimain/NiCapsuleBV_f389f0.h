// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiCapsuleBV: EXE_RTTI
// unknown08, unknown0C, unknown10, unknown14, unknown18, unknown1C, unknown20, capsule, CapsuleShape, shapeData, radius, IsEqual, IsSameVolume, Differs, CopyMembers, UpdateCapsule: GUESS(low)
#pragma once

#include "NiBoundingVolume_f25b40.h"

class CapsuleShape
{
public:
    bool IsEqual(const CapsuleShape& other) const;
    std::uint8_t shapeData[0x18];
    float radius;
};

class NiCapsuleBV : public NiBoundingVolume
{
public:
    void UpdateCapsule();
    void CopyMembers(const NiCapsuleBV& other);
    bool IsSameVolume(const NiBoundingVolume& other) const;
    bool Differs(const NiBoundingVolume& other) const;

private:
    std::uint32_t unknown08;
    std::uint32_t unknown0C;
    std::uint32_t unknown10;
    std::uint32_t unknown14;
    std::uint32_t unknown18;
    std::uint32_t unknown1C;
    std::uint32_t unknown20;
    CapsuleShape capsule;
};
