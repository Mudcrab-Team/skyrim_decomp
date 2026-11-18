// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf5dccc0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v2
#pragma once
#include "WeaponEnchantmentControllerLayout.h"
class FieldLeaf5dccc0 : public ResearchLayouts::WeaponEnchantmentControllerLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::WeaponEnchantmentControllerLayout, target) == 16, "represented field offset");
static_assert(sizeof(FieldLeaf5dccc0) == sizeof(ResearchLayouts::WeaponEnchantmentControllerLayout), "source container adds no storage");
