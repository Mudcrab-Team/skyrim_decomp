// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeafc25a80, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout. Stamped as a twin of matched 0x14a99d0 (unmapped/fields/FieldLeaf14a99d0): source copied, names replaced by placeholders.
// Origin: represented-field-leaf v1
#pragma once
#include "NativeFunctionLayout.h"
class FieldLeafc25a80 : public ResearchLayouts::NativeFunctionBaseLayout {
public:
    void* Read();
};
static_assert(offsetof(ResearchLayouts::NativeFunctionBaseLayout, stateName) == 32, "represented field offset");
static_assert(sizeof(FieldLeafc25a80) == sizeof(ResearchLayouts::NativeFunctionBaseLayout), "source container adds no storage");
