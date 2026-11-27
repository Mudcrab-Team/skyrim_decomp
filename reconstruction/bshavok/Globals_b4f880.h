// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// hkLargeBlockAllocator: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// hkLargeBlockAllocator::Func00dd91f0: GUESS(low); placeholder name
// padding_8_: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

struct hkReferencedObject
{
    void removeReference();
};
extern int Data0102e388;
extern int Data010d7c80;
// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct hkLargeBlockAllocator
{
  public:
    int *m_p;
    char padding_8_[184];
    hkReferencedObject *m_r;
    void Func00dd91f0();
};

struct Globals
{
};
