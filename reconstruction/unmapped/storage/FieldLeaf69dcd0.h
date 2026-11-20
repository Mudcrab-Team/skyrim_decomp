// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf69dcd0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "FieldRecoveryStorageLayout.h"
class FieldLeaf69dcd0 : public ResearchLayouts::FieldRecoveryStorageLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::FieldRecoveryStorageLayout, baseObject) == 64, "represented field offset");
static_assert(sizeof(FieldLeaf69dcd0) == sizeof(ResearchLayouts::FieldRecoveryStorageLayout), "source container adds no storage");
