// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Projectile: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// Projectile::Func007c7fa0: GUESS(low); placeholder name
// padding_0_: GUESS(low); placeholder name
#pragma once

namespace f3m_007c7fa0 {
namespace task1023 {
struct LoadBuffer {
    void Func006e0750(void*,unsigned int);
    unsigned int Func006e0670();
};


struct Sound {bool Func00bd0390(); void Func00bd0140(); void Func00bd03b0();};
// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct Projectile
{
  public:
    char padding_0_[316];
    Sound sound;
    void Func007c7fa0();
};
}
}
