// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Decoded: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// Decoded::Func006d3130: GUESS(low); placeholder name
#pragma once

#include <string.h>

namespace f3m_006d3130 {
namespace moved_record {
struct Basic;
struct Exterior;
struct Interior;




struct Id { unsigned char bytes[3]; unsigned Func006d6cd0() const; };
struct Vec { float x,y,z; };

struct Basic { Id ref; Vec pos, rot; };
struct Interior { Id ref; Vec pos, rot; unsigned char flag; Id cell; };
// The record is stored packed, so the vectors sit at odd offsets.
#pragma pack(push, 1)
struct Exterior { Id ref; Vec pos, rot; Id world; short x,y; };
#pragma pack(pop)

struct Decoded { unsigned ref,cell,world; int x,y; Vec pos,rot; unsigned char flag;
void basic(const Basic&); void interior(const Interior&); void Func006d3130(const Exterior&); };
}
}
