// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf17ee20, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "FieldRecoveryStorageLayout.h"
class FieldLeaf17ee20 : public ResearchLayouts::NonActorMagicTargetSecondaryStorageLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::NonActorMagicTargetSecondaryStorageLayout, targetObject) == 24, "represented field offset");
static_assert(sizeof(FieldLeaf17ee20) == sizeof(ResearchLayouts::NonActorMagicTargetSecondaryStorageLayout), "source container adds no storage");
