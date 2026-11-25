// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// NiHalfSpaceBV: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// NiHalfSpaceBV::Func00e9cb50: GUESS(low); placeholder name
// padding_8_, padding_39_: GUESS(low); placeholder name
#pragma once

namespace fnv_00e9cb50 {
struct NiStream;

struct NiBoundingVolume
{
    virtual ~NiBoundingVolume();
};


struct NiStream
{
};
// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct NiObject
{
  public:
    virtual void LinkObject(NiStream&);
};
struct NiPlane
{
    void LoadBinary(NiStream&);
};
struct NiPoint3
{
    void LoadBinary(NiStream&);
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct NiHalfSpaceBV : NiObject
{
  public:
    char padding_8_[48];
    NiPlane m_kHalfSpacePlane;
    char padding_39_[15];
    NiPoint3 m_kCenter;
    void Func00e9cb50(NiStream&);
};

}
