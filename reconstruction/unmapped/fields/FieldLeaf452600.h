// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf452600, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout. Stamped as a twin of matched 0x14a99c0 (unmapped/fields/FieldLeaf14a99c0): source copied, names replaced by placeholders.
// Origin: represented-field-leaf v1
#pragma once
#include "NativeFunctionLayout.h"

class FieldLeaf452600 : public ResearchLayouts::NativeFunctionBaseLayout {
public:
    void* Read();
};

static_assert(sizeof(FieldLeaf452600) == sizeof(ResearchLayouts::NativeFunctionBaseLayout), "source container adds no storage");
