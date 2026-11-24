// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// hkpRayCollidableFilter: CRASHLOGGER_PDB(59818@2026.10.24)
// hkpRayCollidableFilter::isCollisionEnabled_140AC7400: CRASHLOGGER_PDB(59818@2026.10.24)
// padding_0_: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

struct hkBoolE46D
{
    char m_cBooleanValue;
    hkBoolE46D(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
};

class hkFilterE46D
{
  public:
    virtual void V0();
    virtual hkBoolE46D IsCollisionEnabled(void* a, void* b);
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct hkWorldE46D
{
  public:
    char padding_0_[40];
    hkFilterE46D m_iFilter;
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
class hkpRayCollidableFilter
{
  public:
    char padding_0_[40];
    hkWorldE46D *m_pOwningWorld;
    hkBoolE46D isCollisionEnabled_140AC7400(void* a, void* b);
};

struct Globals
{
};
