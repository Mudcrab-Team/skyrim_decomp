// Code origin: GetData2, IsMedicine, IsPoison and IsFood bodies written from the local listings; declarations and stand-in layout added to the existing unit header.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x1466b0 AlchemyItem::GetData2
// 0x146910 AlchemyItem::IsMedicine
// 0x146940 AlchemyItem::IsPoison
// 0x1468b0 AlchemyItem::IsFood
#include "AlchemyItem.h"
AlchemyData* AlchemyItem::GetData2() { return reinterpret_cast<AlchemyData*>(&cost); }
bool AlchemyItem::IsMedicine() const { return ((GetData()->flags >> 16) & 1) != 0; }
bool AlchemyItem::IsPoison() const { return ((GetData()->flags >> 17) & 1) != 0; }
bool AlchemyItem::IsFood() const { return (GetData()->flags & 2) != 0 && !Unk_61(); }
