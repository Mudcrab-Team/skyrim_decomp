// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeafc65930, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout. Stamped as a twin of matched 0x5dcce0 (unmapped/fields/FieldLeaf5dcce0): source copied, names replaced by placeholders.
// Origin: represented-field-leaf v2
#pragma once
#include "WeaponEnchantmentControllerLayout.h"

class FieldLeafc65930 : public ResearchLayouts::WeaponEnchantmentControllerLayout {
public:
    const void* Read();
};

static_assert(sizeof(FieldLeafc65930) == sizeof(ResearchLayouts::WeaponEnchantmentControllerLayout), "source container adds no storage");
