// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf82cef0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v1
#pragma once
#include "CombatInventoryItemLayout.h"
class FieldLeaf82cef0 : public ResearchLayouts::CombatInventoryItemLayout {
public:
    bool Read();
};
static_assert(offsetof(ResearchLayouts::CombatInventoryItemLayout, item) == 16, "represented field offset");
static_assert(sizeof(FieldLeaf82cef0) == sizeof(ResearchLayouts::CombatInventoryItemLayout), "source container adds no storage");
