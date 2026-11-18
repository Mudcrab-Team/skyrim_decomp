// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf142100, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "BoundArgumentCallableLayout.h"
class FieldLeaf142100 : public ResearchLayouts::BoundArgumentCallableLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::BoundArgumentCallableLayout, callable) == 8, "represented field offset");
static_assert(sizeof(FieldLeaf142100) == sizeof(ResearchLayouts::BoundArgumentCallableLayout), "source container adds no storage");
