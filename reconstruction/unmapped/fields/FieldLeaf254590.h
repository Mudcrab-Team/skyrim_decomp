// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf254590, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v2
#pragma once
#include "TESRegionGrassObjectLayout.h"
class FieldLeaf254590 : public ResearchLayouts::TESRegionGrassObjectLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::TESRegionGrassObjectLayout, value10) == 16, "represented field offset");
static_assert(sizeof(FieldLeaf254590) == sizeof(ResearchLayouts::TESRegionGrassObjectLayout), "source container adds no storage");
