// Code origin: GetData2, IsFood and InitChunk bodies written from the local listings; declarations and stand-in layout added to the existing unit header.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x14f8a0 IngredientItem::InitChunk
// 0x14fd00 IngredientItem::GetData2
// 0x14fd60 IngredientItem::IsFood
#include "IngredientItem_14f8a0.h"
#include <intrin.h>
void IngredientItem::InitChunk()
{
    // The listing shows a 32-bit byte swap (bswap) of the cost field.
    cost = static_cast<int>(_byteswap_ulong(static_cast<unsigned long>(cost)));
    // The listing shows a 32-bit byte swap (bswap) of the flags field.
    flags = _byteswap_ulong(flags);
}
IngredientData* IngredientItem::GetData2() { return reinterpret_cast<IngredientData*>(&cost); }
bool IngredientItem::IsFood() const { return ((GetData()->flags >> 1) & 1) != 0; }
