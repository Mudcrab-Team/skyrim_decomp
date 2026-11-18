// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf3f0f50, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "EventFactoryNameLinkStorageLayout.h"
class FieldLeaf3f0f50 : public ResearchLayouts::EventFactoryNameLinkStorageLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::EventFactoryNameLinkStorageLayout, name) == 8, "represented field offset");
static_assert(sizeof(FieldLeaf3f0f50) == sizeof(ResearchLayouts::EventFactoryNameLinkStorageLayout), "source container adds no storage");
