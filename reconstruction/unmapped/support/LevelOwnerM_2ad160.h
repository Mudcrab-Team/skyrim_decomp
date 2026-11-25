// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// LevelOwnerM: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// LevelOwnerM::Func004c8f40: GUESS(low); placeholder name
// padding_0_, padding_38_: GUESS(low); placeholder name
#pragma once

struct LevelDataM;
struct LevelSourceM;


// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct LevelDataM
{
  public:
    char padding_0_[18872];
    int level98;
};

struct LevelSourceM
{
    int GetLevelM();
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct LevelOwnerM
{
  public:
    char padding_0_[48];
    LevelSourceM *source20;
    char padding_38_[8];
    LevelDataM *data28;
    float Func004c8f40();
};
