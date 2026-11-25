// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func00a34480_cls: GUESS(low); placeholder name
// Func00a34480_cls::Func00a34480: GUESS(low); placeholder name
// padding_0_, padding_42_: GUESS(low); placeholder name
#pragma once

struct Func00a34480_obj;


struct Func00a34480_obj
{
    virtual void V00();
    virtual void V01();
    virtual Func00a34480_obj* V02();
    Func00a34480_obj* m_pNext;
    unsigned short m_word08;
    unsigned short unk0a;
    float m_f0c;
};

extern int Data011f36b4;

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct Func00a34480_cls
{
  public:
    char padding_0_[64];
    unsigned short m_word24;
    char padding_42_[2];
    float m_f28;
    bool AssignControllers(void* a1, Func00a34480_obj* a2);
    bool Func00a34480(void* a1, Func00a34480_obj* a2);
};
