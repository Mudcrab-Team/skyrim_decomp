// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf38b6a0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "FieldRecoveryStorageLayout.h"
class FieldLeaf38b6a0 : public ResearchLayouts::BodyPartDataFieldStorageLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::BodyPartDataFieldStorageLayout, parts) == 80, "represented field offset");
static_assert(sizeof(FieldLeaf38b6a0) == sizeof(ResearchLayouts::BodyPartDataFieldStorageLayout), "source container adds no storage");
