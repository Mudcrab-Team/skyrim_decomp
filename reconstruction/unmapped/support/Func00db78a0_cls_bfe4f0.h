// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func00db78a0_cls: GUESS(low); placeholder name
// Func00db78a0_cls::Func00db78a0: GUESS(low); placeholder name
// padding_0_: GUESS(low); placeholder name
#pragma once

struct Func00db78a0_item;


// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct Func00db78a0_item
{
  public:
    char padding_0_[32];
    void *m_0c;
};

class Func00db78a0_cls
{
  public:
    virtual void vSlot00();
    virtual void vSlot04();
    virtual void vSlot08();
    virtual void vSlot0c(void* field, void* item);
    void Func00db78a0(Func00db78a0_item** a, void** b);
};
