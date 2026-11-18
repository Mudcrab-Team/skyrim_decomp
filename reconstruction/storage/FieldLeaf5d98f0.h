// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf5d98f0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "FieldRecoveryStorageLayout.h"
class FieldLeaf5d98f0 : public ResearchLayouts::NonActorMagicTargetSecondaryStorageLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::NonActorMagicTargetSecondaryStorageLayout, activeEffects) == 32, "represented field offset");
static_assert(sizeof(FieldLeaf5d98f0) == sizeof(ResearchLayouts::NonActorMagicTargetSecondaryStorageLayout), "source container adds no storage");
