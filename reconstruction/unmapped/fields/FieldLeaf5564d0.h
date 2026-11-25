// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf5564d0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout. Stamped as a twin of matched 0x82cef0 (unmapped/fields/FieldLeaf82cef0): source copied, names replaced by placeholders.
// Origin: represented-field-leaf v1
#pragma once
#include "CombatInventoryItemLayout.h"

class FieldLeaf5564d0 : public ResearchLayouts::CombatInventoryItemLayout {
public:
    bool Read();
};

static_assert(sizeof(FieldLeaf5564d0) == sizeof(ResearchLayouts::CombatInventoryItemLayout), "source container adds no storage");
