// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf14acd50, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v2
#pragma once
#include "NativeFunctionLayout.h"
class FieldLeaf14acd50 : public ResearchLayouts::NativeFunctionBaseLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::NativeFunctionBaseLayout, docString) == 72, "represented field offset");
static_assert(sizeof(FieldLeaf14acd50) == sizeof(ResearchLayouts::NativeFunctionBaseLayout), "source container adds no storage");
