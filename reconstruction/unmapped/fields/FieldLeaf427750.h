// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf427750, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout. Stamped as a twin of matched 0x9fe0d0 (unmapped/fields/FieldLeaf9fe0d0): source copied, names replaced by placeholders.
// Origin: represented-field-leaf v1
#pragma once
#include "NativeFunctionLayout.h"
class FieldLeaf427750 : public ResearchLayouts::NativeFunctionLayout {
public:
    bool Read();
};
static_assert(offsetof(ResearchLayouts::NativeFunctionLayout, callback) == 80, "represented field offset");
static_assert(sizeof(FieldLeaf427750) == sizeof(ResearchLayouts::NativeFunctionLayout), "source container adds no storage");
