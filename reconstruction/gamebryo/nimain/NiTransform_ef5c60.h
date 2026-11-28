// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// NiTransform, NiTransform::IsZero: CRASHLOGGER_PDB(59818@2026.10.24)
// NiMatrix3ef5c60, NiPoint3ef5c60, gIdentityMatrix, gZeroTranslate, gScaleEpsilon, rotate, translate, scale: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct NiMatrix3ef5c60
{
    bool operator==(const NiMatrix3ef5c60& a_rhs) const
    {
        return entry[0][0] == a_rhs.entry[0][0] &&
               entry[0][1] == a_rhs.entry[0][1] &&
               entry[0][2] == a_rhs.entry[0][2] &&
               entry[1][0] == a_rhs.entry[1][0] &&
               entry[1][1] == a_rhs.entry[1][1] &&
               entry[1][2] == a_rhs.entry[1][2] &&
               entry[2][0] == a_rhs.entry[2][0] &&
               entry[2][1] == a_rhs.entry[2][1] &&
               entry[2][2] == a_rhs.entry[2][2];
    }

    float entry[3][3];  // 00
};
static_assert(sizeof(NiMatrix3ef5c60) == 0x24, "NiMatrix3ef5c60 size");

struct NiPoint3ef5c60
{
    bool operator==(const NiPoint3ef5c60& a_rhs) const
    {
        return x == a_rhs.x && y == a_rhs.y && z == a_rhs.z;
    }

    float x;  // 00
    float y;  // 04
    float z;  // 08
};
static_assert(sizeof(NiPoint3ef5c60) == 0x0C, "NiPoint3ef5c60 size");

extern const NiMatrix3ef5c60 gIdentityMatrix;
extern const NiPoint3ef5c60 gZeroTranslate;
extern const double gScaleEpsilon;

class NiTransform
{
public:
    bool IsZero() const;  // compared: 0xef5c60

    NiMatrix3ef5c60 rotate;     // 00
    NiPoint3ef5c60  translate;  // 24
    float           scale;      // 30
};
static_assert(offsetof(NiTransform, translate) == 0x24, "translate offset");
static_assert(offsetof(NiTransform, scale) == 0x30, "scale offset");
