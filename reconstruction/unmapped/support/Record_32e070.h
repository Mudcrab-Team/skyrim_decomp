// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Record: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// Record::Func0050d410: GUESS(low); placeholder name
// padding_0_: GUESS(low); placeholder name
#pragma once

namespace f3m_0050d410 {
namespace match50d410 {
struct Input;


// Byte-swap intrinsic: the target code swaps the field with a bswap instruction.
extern "C" unsigned long _byteswap_ulong(unsigned long);
// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct Input
{
  public:
    char padding_0_[745];
    bool swap;
    void Func00447d60(void*,unsigned);
};
// Byte-swap intrinsic: the target code swaps the field with a bswap instruction.
inline void Swap(unsigned long& value){value=_byteswap_ulong(value);}
struct Record {
unsigned long unk00;
unsigned long unk04;
unsigned long unk08;
unsigned long unk0C;
unsigned long unk10;
unsigned long unk14;
unsigned long unk18;
unsigned long unk1C;
unsigned long unk20;
void Func0050d410(Input*);
};
}
}
