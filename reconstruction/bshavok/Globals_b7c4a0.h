// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// ProcessChildLoop: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// padding_0_: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

struct ChildObj;
struct InnerObj;
struct ParamObj;


struct InnerObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(void* param);
};

struct ParamObj;

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct ChildObj
{
  public:
    char padding_0_[56];
    int m_28;
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct ParamObj
{
  public:
    char padding_0_[16];
    ChildObj *m_08;
    InnerObj* Func00c93570();
};

void Func00d88040(int value);
void ApplyActionPhases(ParamObj* param);

struct Globals
{
};
