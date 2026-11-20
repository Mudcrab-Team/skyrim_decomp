// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeafb9ddd0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "FieldRecoveryStorageLayout.h"
class FieldLeafb9ddd0 : public ResearchLayouts::CharacterProxyFieldStorageLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::CharacterProxyFieldStorageLayout, velocity) == 96, "represented field offset");
static_assert(sizeof(FieldLeafb9ddd0) == sizeof(ResearchLayouts::CharacterProxyFieldStorageLayout), "source container adds no storage");
