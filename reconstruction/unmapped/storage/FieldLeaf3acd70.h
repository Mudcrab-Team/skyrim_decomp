// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf3acd70, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "../../bscore/EventFactoryNameLinkStorageLayout.h"
class FieldLeaf3acd70 : public ResearchLayouts::EventFactoryNameLinkStorageLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::EventFactoryNameLinkStorageLayout, name) == 8, "represented field offset");
static_assert(sizeof(FieldLeaf3acd70) == sizeof(ResearchLayouts::EventFactoryNameLinkStorageLayout), "source container adds no storage");
