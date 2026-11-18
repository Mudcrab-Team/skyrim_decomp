// Code origin: Getter bodies (member reads, address of data) written from the local listings; declarations added to the existing unit header.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x14e750 EnchantmentItem::GetCastingType
// 0x14e7a0 EnchantmentItem::GetDelivery
// 0x14e7b0 EnchantmentItem::GetSpellType
// 0x14e770 EnchantmentItem::GetData2
#include "EnchantmentItem.h"
int EnchantmentItem::GetCastingType() const { return data.castingType; }
int EnchantmentItem::GetDelivery() const { return data.delivery; }
int EnchantmentItem::GetSpellType() const { return data.spellType; }
EnchantmentItem::Data* EnchantmentItem::GetData2() { return &data; }
