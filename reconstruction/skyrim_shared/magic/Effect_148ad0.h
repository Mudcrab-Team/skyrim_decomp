// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// ValueOwner: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// ValueOwner::Func004021b0: GUESS(low); placeholder name
// padding_0_: GUESS(low); placeholder name
// Effect: GUESS(low); placeholder name
#pragma once

namespace f3m_004021b0 {
struct StoredValue;


struct StoredValue
{
    int unk00, unk04;
    StoredValue();
    ~StoredValue();
    void Func005ae2d0(const StoredValue* value, int option);
};
// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct ValueOwner
{
  public:
    char padding_0_[32];
    StoredValue value;
    void Func004021b0(const StoredValue* supplied);
};
}

struct Effect
{
};
