// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf14acc30, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v2
#pragma once
#include "NativeFunctionLayout.h"
class FieldLeaf14acc30 : public ResearchLayouts::NativeFunctionBaseLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::NativeFunctionBaseLayout, name) == 16, "represented field offset");
static_assert(sizeof(FieldLeaf14acc30) == sizeof(ResearchLayouts::NativeFunctionBaseLayout), "source container adds no storage");
