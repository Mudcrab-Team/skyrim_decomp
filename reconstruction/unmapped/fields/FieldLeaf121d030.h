// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf121d030, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout. Stamped as a twin of matched 0x14a99d0 (unmapped/fields/FieldLeaf14a99d0): source copied, names replaced by placeholders.
// Origin: represented-field-leaf v1
#pragma once
#include "NativeFunctionLayout.h"

class FieldLeaf121d030 : public ResearchLayouts::NativeFunctionBaseLayout {
public:
    void* Read();
};

static_assert(sizeof(FieldLeaf121d030) == sizeof(ResearchLayouts::NativeFunctionBaseLayout), "source container adds no storage");
