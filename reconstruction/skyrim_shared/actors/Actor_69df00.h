// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Actor: CRASHLOGGER_PDB(59818@2026.10.24)
// Actor::IsInFaction_1405F8500: CRASHLOGGER_PDB(59818@2026.10.24)
// padding_0_, padding_48_: GUESS(low); placeholder name
#pragma once

namespace f3m_006f8ff0 {
struct List6f8;
struct Owner6f8;


struct List6f8{bool Func0041f9e0(void* item);bool Func0041f9a0(void* item);};
struct Holder6f8{List6f8* Func0040e4f0();};
struct Set6f8{bool Func0044fc00(void* item);};
struct Owner6f8{char pad[0x30];Set6f8 set;};
// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct Actor
{
  public:
    char padding_0_[64];
    Owner6f8 *owner;
    char padding_48_[40];
    Holder6f8 holder;
    bool IsInFaction_1405F8500(void* item);
};
}
