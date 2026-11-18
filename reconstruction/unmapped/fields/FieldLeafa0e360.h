// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeafa0e360, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v1
#pragma once
#include "NativeFunctionLayout.h"
class FieldLeafa0e360 : public ResearchLayouts::NativeFunctionLayout {
public:
    bool Read();
};
static_assert(offsetof(ResearchLayouts::NativeFunctionLayout, callback) == 80, "represented field offset");
static_assert(sizeof(FieldLeafa0e360) == sizeof(ResearchLayouts::NativeFunctionLayout), "source container adds no storage");
