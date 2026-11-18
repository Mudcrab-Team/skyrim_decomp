// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf5dccd0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v2
#pragma once
#include "WeaponEnchantmentControllerLayout.h"
class FieldLeaf5dccd0 : public ResearchLayouts::WeaponEnchantmentControllerLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::WeaponEnchantmentControllerLayout, art) == 32, "represented field offset");
static_assert(sizeof(FieldLeaf5dccd0) == sizeof(ResearchLayouts::WeaponEnchantmentControllerLayout), "source container adds no storage");
