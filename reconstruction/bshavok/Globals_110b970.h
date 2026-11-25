// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// ClearFlagsAndMarkDirty: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// padding_0_, padding_28_: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

struct D942F0Array;
struct D942F0Island;


struct D942F0Array
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    D942F0Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct D942F0Island
{
  public:
    char padding_0_[32];
    void *m_pOwningWorld;
    char padding_28_[9];
    unsigned char m_flags;
    void markDirty();
};

void Func00cb6060(D942F0Island* island, void* world, void* context, D942F0Array* out);

struct Globals
{
};
