// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf122800, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "BoundPairCallableLayout.h"
class FieldLeaf122800 : public ResearchLayouts::BoundPairCallableLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::BoundPairCallableLayout, callable) == 8, "represented field offset");
static_assert(sizeof(FieldLeaf122800) == sizeof(ResearchLayouts::BoundPairCallableLayout), "source container adds no storage");
