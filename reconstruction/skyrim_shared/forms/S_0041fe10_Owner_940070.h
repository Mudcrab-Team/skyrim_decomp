// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// S_0041fe10_Owner: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); sibling name, identity with this function unproven
// S_0041fe10_Owner::ReleaseStorage_0041fe10: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); sibling name, identity with this function unproven
// padding_0_: GUESS(low); placeholder name
#pragma once

struct S_0041fe10_Item;


struct S_0041fe10_VB
{
    int unk00;
};
struct S_0041fe10_Item : virtual S_0041fe10_VB
{
    int unk04;
    ~S_0041fe10_Item();
};
// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct S_0041fe10_Owner
{
  public:
    char padding_0_[8];
    S_0041fe10_Item *unk0c;
    void ReleaseStorage_0041fe10();
};
