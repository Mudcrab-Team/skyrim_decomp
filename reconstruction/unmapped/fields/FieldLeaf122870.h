// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf122870, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "BoundArgumentCallableLayout.h"
class FieldLeaf122870 : public ResearchLayouts::BoundArgumentCallableLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::BoundArgumentCallableLayout, callable) == 8, "represented field offset");
static_assert(sizeof(FieldLeaf122870) == sizeof(ResearchLayouts::BoundArgumentCallableLayout), "source container adds no storage");
