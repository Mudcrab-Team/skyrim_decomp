// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf4aa860, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "FirstPersonCameraDataStorageLayout.h"
class FieldLeaf4aa860 : public ResearchLayouts::DebrisEffectDataStorageLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::DebrisEffectDataStorageLayout, debris3D) == 48, "represented field offset");
static_assert(sizeof(FieldLeaf4aa860) == sizeof(ResearchLayouts::DebrisEffectDataStorageLayout), "source container adds no storage");
