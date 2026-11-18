// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf155350, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "FieldRecoveryStorageLayout.h"
class FieldLeaf155350 : public ResearchLayouts::MenuDisplayComponentLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::MenuDisplayComponentLayout, menuDispObject) == 8, "represented field offset");
static_assert(sizeof(FieldLeaf155350) == sizeof(ResearchLayouts::MenuDisplayComponentLayout), "source container adds no storage");
