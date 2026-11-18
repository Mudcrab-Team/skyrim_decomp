// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf11b510, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "BoundPairCallableLayout.h"
class FieldLeaf11b510 : public ResearchLayouts::BoundPairCallableLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::BoundPairCallableLayout, callable) == 8, "represented field offset");
static_assert(sizeof(FieldLeaf11b510) == sizeof(ResearchLayouts::BoundPairCallableLayout), "source container adds no storage");
