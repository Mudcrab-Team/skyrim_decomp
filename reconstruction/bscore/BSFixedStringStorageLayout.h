// Source exposure: community-headers
// BSFixedString, BSFixedStringCS, Color, NiPoint2, NiPoint3, NiColor, NiColorA,
// NiPointer, BSTSmartPointer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// entry, value: GUESS(medium)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSFixedStringCSLayout, BSFixedStringLayout, BSTSmartPointerLayout, ColorLayout, CombatInventoryItemSlotLayout, NiColorALayout, NiColorLayout, NiPoint2Layout, NiPoint3Layout, NiPointerLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/BSFixedStringLayout.h.
// CombatInventoryItemSlotStorageLayout, BSFixedStringStorageLayout, BSFixedStringCSStorageLayout, ColorStorageLayout, NiPoint2StorageLayout, NiPoint3StorageLayout, NiColorStorageLayout, NiColorAStorageLayout, NiPointerStorageLayout, BSTSmartPointerStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
namespace ResearchLayouts {
class BGSEquipSlot;
struct CombatInventoryItemSlotStorageLayout { BGSEquipSlot* equipSlot; std::uint32_t slot; };
static_assert(sizeof(CombatInventoryItemSlotStorageLayout) == 16, "value representation");
struct BSFixedStringStorageLayout { const char* entry; };
static_assert(sizeof(BSFixedStringStorageLayout) == 8, "value representation");
struct BSFixedStringCSStorageLayout { const char* entry; };
static_assert(sizeof(BSFixedStringCSStorageLayout) == 8, "value representation");
struct ColorStorageLayout { std::uint8_t red; std::uint8_t green; std::uint8_t blue; std::uint8_t alpha; };
static_assert(sizeof(ColorStorageLayout) == 4, "value representation");
struct NiPoint2StorageLayout { float x; float y; };
static_assert(sizeof(NiPoint2StorageLayout) == 8, "value representation");
struct NiPoint3StorageLayout { float x; float y; float z; };
static_assert(sizeof(NiPoint3StorageLayout) == 12, "value representation");
struct NiColorStorageLayout { float red; float green; float blue; };
static_assert(sizeof(NiColorStorageLayout) == 12, "value representation");
struct NiColorAStorageLayout { float red; float green; float blue; float alpha; };
static_assert(sizeof(NiColorAStorageLayout) == 16, "value representation");
template<class T> struct NiPointerStorageLayout { T* value; };
template<class T> struct BSTSmartPointerStorageLayout { T* value; };
}
