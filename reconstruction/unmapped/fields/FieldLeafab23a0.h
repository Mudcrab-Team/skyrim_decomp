// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeafab23a0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout. Stamped as a twin of matched 0x14a9ad0 (unmapped/fields/FieldLeaf14a9ad0): source copied, names replaced by placeholders.
// Origin: represented-field-leaf v1
#pragma once
#include "NativeFunctionLayout.h"
class FieldLeafab23a0 : public ResearchLayouts::NativeFunctionBaseLayout {
public:
    void* Read();
};
static_assert(offsetof(ResearchLayouts::NativeFunctionBaseLayout, docString) == 72, "represented field offset");
static_assert(sizeof(FieldLeafab23a0) == sizeof(ResearchLayouts::NativeFunctionBaseLayout), "source container adds no storage");
