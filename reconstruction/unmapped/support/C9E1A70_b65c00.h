// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// C9E1A70: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// C9E1A70::Func009e1a70: GUESS(low); placeholder name
// padding_0_: GUESS(low); placeholder name
#pragma once

namespace f3m_009e1a70 {

struct Vec9E1A70
{
    float x, y, z, w;
    void Func008d2970(const void* kTransform, const void* kVector);
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct C9E1A70
{
  public:
    char padding_0_[48];
    Vec9E1A70 m_20;
    Vec9E1A70 m_30;
    void Func009e1a70(const void* kTransformA, const void* kTransformB, const void* kVector);
};

}
