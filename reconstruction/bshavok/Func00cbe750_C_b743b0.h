// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func00cbe750_C: GUESS(low); placeholder name
// Func00cbe750_C::Func00cbe750: GUESS(low); placeholder name
// padding_0_: GUESS(low); placeholder name
#pragma once

class hkBoolCBE7
{
  public:
    hkBoolCBE7()
    {}
    hkBoolCBE7(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

class hkTransformCBE7
{
  public:
    float m_data[16];

    hkBoolCBE7 IsOrthonormal(float fEpsilon) const;
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
class Func00cbe750_C
{
  public:
    char padding_0_[48];
    hkTransformCBE7 m_kPointA;
    hkTransformCBE7 m_kPointB;
    hkBoolCBE7 Func00cbe750() const;
};
