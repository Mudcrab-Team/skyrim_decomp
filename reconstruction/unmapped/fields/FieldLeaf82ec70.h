// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf82ec70, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v1
#pragma once
#include "CombatInventoryItemMagicLayout.h"
class FieldLeaf82ec70 : public ResearchLayouts::CombatInventoryItemMagicLayout {
public:
    void* Read();
};
static_assert(offsetof(ResearchLayouts::CombatInventoryItemMagicLayout, item) == 16, "represented field offset");
static_assert(sizeof(FieldLeaf82ec70) == sizeof(ResearchLayouts::CombatInventoryItemMagicLayout), "source container adds no storage");
