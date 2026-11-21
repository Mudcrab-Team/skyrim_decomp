// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeafd94150, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout. Stamped as a twin of matched 0x14a99c0 (unmapped/fields/FieldLeaf14a99c0): source copied, names replaced by placeholders.
// Origin: represented-field-leaf v1
#pragma once
#include "NativeFunctionLayout.h"
class FieldLeafd94150 : public ResearchLayouts::NativeFunctionBaseLayout {
public:
    void* Read();
};
static_assert(offsetof(ResearchLayouts::NativeFunctionBaseLayout, objectName) == 24, "represented field offset");
static_assert(sizeof(FieldLeafd94150) == sizeof(ResearchLayouts::NativeFunctionBaseLayout), "source container adds no storage");
