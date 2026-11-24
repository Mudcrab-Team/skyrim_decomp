// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// hkpNullCollisionFilter: CRASHLOGGER_PDB(59818@2026.10.24)
// hkpNullCollisionFilter::Func1_v4: CRASHLOGGER_PDB(59818@2026.10.24)
// padding_8_, padding_39_: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
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
struct hkpNullCollisionFilter : NiObject
{
  public:
    char padding_8_[48];
    NiPlane m_kHalfSpacePlane;
    char padding_39_[23];
    NiPoint3 m_kCenter;
    void Func1_v4(NiStream&);
};

}

struct Globals
{
};
