// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf890980, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "skyrim/ai/combat/CombatPathRequestPointerStorageLayout.h"
class FieldLeaf890980 : public ResearchLayouts::CombatPathRequestPointerStorageLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::CombatPathRequestPointerStorageLayout, requestPointer) == 56, "represented field offset");
static_assert(sizeof(FieldLeaf890980) == sizeof(ResearchLayouts::CombatPathRequestPointerStorageLayout), "source container adds no storage");
