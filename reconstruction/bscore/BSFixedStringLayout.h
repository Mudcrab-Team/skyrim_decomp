// Source exposure: community-headers
// Drafted by GPT-6.1 Sol; p106 value layouts adapted from pinned community declarations.
// NiPointer, BSTSmartPointer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// entry, value: GUESS(medium)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSFixedStringCSLayout, BSFixedStringLayout, BSTSmartPointerLayout, ColorLayout, CombatInventoryItemSlotLayout, NiColorALayout, NiColorLayout, NiPoint2Layout, NiPoint3Layout, NiPointerLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
namespace ResearchLayouts {
class BGSEquipSlot;
struct CombatInventoryItemSlotLayout { BGSEquipSlot* equipSlot; std::uint32_t slot; };
static_assert(sizeof(CombatInventoryItemSlotLayout) == 16, "value representation");
struct BSFixedStringLayout { const char* entry; };
static_assert(sizeof(BSFixedStringLayout) == 8, "value representation");
struct BSFixedStringCSLayout { const char* entry; };
static_assert(sizeof(BSFixedStringCSLayout) == 8, "value representation");
struct ColorLayout { std::uint8_t red; std::uint8_t green; std::uint8_t blue; std::uint8_t alpha; };
static_assert(sizeof(ColorLayout) == 4, "value representation");
struct NiPoint2Layout { float x; float y; };
static_assert(sizeof(NiPoint2Layout) == 8, "value representation");
struct NiPoint3Layout { float x; float y; float z; };
static_assert(sizeof(NiPoint3Layout) == 12, "value representation");
struct NiColorLayout { float red; float green; float blue; };
static_assert(sizeof(NiColorLayout) == 12, "value representation");
struct NiColorALayout { float red; float green; float blue; float alpha; };
static_assert(sizeof(NiColorALayout) == 16, "value representation");
template<class T> struct NiPointerLayout { T* value; };
template<class T> struct BSTSmartPointerLayout { T* value; };
}
