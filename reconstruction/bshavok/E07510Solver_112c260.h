// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// E07510Solver: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// E07510Solver::Func00e07510: GUESS(low); placeholder name
// padding_0_: GUESS(low); placeholder name
#pragma once

struct E07510Input;


// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct E07510Input
{
  public:
    char padding_0_[62];
    unsigned char m_type;
};

struct E07510Solver
{
    void Func00e07070(void* b, void* c, void* d);
    void AdjustLimits(E07510Input* a, void* b, void* c);
    void Func00e07510(E07510Input* a, void* b, void* c, void* d);
};
