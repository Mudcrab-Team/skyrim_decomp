// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf14a99d0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v1
#pragma once
#include "NativeFunctionLayout.h"
class FieldLeaf14a99d0 : public ResearchLayouts::NativeFunctionBaseLayout {
public:
    void* Read();
};
static_assert(offsetof(ResearchLayouts::NativeFunctionBaseLayout, stateName) == 32, "represented field offset");
static_assert(sizeof(FieldLeaf14a99d0) == sizeof(ResearchLayouts::NativeFunctionBaseLayout), "source container adds no storage");
