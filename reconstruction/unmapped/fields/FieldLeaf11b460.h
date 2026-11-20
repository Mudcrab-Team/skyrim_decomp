// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf11b460, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "BoundArgumentCallableLayout.h"
class FieldLeaf11b460 : public ResearchLayouts::BoundArgumentCallableLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::BoundArgumentCallableLayout, callable) == 8, "represented field offset");
static_assert(sizeof(FieldLeaf11b460) == sizeof(ResearchLayouts::BoundArgumentCallableLayout), "source container adds no storage");
