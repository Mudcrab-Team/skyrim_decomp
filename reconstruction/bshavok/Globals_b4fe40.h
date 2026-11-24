// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// hkpPrismaticConstraintData: CRASHLOGGER_PDB(59818@2026.10.24)
// hkpPrismaticConstraintData::Routine140A71580: CRASHLOGGER_PDB(59818@2026.10.24)
// padding_0_, padding_b0_: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

class hkBoolD4FD
{
  public:
    hkBoolD4FD(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

extern float Data01017d00;

class hkTransformD4FD
{
  public:
    hkBoolD4FD IsOrthonormal(float epsilon) const;
    float m_data[16];
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
class hkpPrismaticConstraintData
{
  public:
    char padding_0_[48];
    hkTransformD4FD m_kPointA;
    hkTransformD4FD m_kPointB;
    char padding_b0_[48];
    float m_kMinimumCorner;
    float m_kMaximumCorner;
    hkBoolD4FD Routine140A71580() const;
};

struct Globals
{
};
