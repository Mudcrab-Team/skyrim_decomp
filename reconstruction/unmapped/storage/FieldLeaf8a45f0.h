// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf8a45f0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "skyrim/ai/combat/CombatPathRequestPointerStorageLayout.h"
class FieldLeaf8a45f0 : public ResearchLayouts::CombatPathRequestPointerStorageLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::CombatPathRequestPointerStorageLayout, requestPointer) == 56, "represented field offset");
static_assert(sizeof(FieldLeaf8a45f0) == sizeof(ResearchLayouts::CombatPathRequestPointerStorageLayout), "source container adds no storage");
