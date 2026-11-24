// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func00aa1fd0_cls: GUESS(low); placeholder name
// Func00aa1fd0_cls::AdvanceChars: GUESS(low); placeholder name
// padding_0_, padding_c_: GUESS(low); placeholder name
#pragma once

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
class Func00aa1fd0_cls
{
  public:
    char padding_0_[8];
    int m_04;
    char padding_c_[12];
    int(* m_0c)(Func00aa1fd0_cls* self, char* s, int a, int* out, int b);
    unsigned int AdvanceChars(char* s);
};
