// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// NiCollisionData: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// NiCollisionData::SetBoundingVolume: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// padding_0_, padding_18_, NiCollisionOwner, m_7c, padding_0_7c_: GUESS(low); placeholder name
#pragma once

namespace fnv_00eace50 {
struct NiBoundingVolume;

struct NiCollisionOwner
{
    char padding_0_7c_[0x7c];
    char m_7c;
};

struct NiPoint3
{
    float x, y, z;
};


struct NiBoundingVolume
{
    virtual void v0();
    virtual void v1();
    virtual void v2(int);
    virtual void v3();
    virtual void v4();
    virtual void v5(NiBoundingVolume*, void*);
    virtual NiBoundingVolume* v6();
};
// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct NiCollisionData
{
  public:
    char padding_0_[16];
    NiCollisionOwner *_08;
    char padding_18_[32];
    NiBoundingVolume *_2c;
    NiBoundingVolume *_30;
    void SetBoundingVolume(NiBoundingVolume* pkBV);
};
}
