// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeafa15680, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v1
#pragma once
#include "NativeFunctionLayout.h"
class FieldLeafa15680 : public ResearchLayouts::NativeFunctionLayout {
public:
    bool Read();
};
static_assert(offsetof(ResearchLayouts::NativeFunctionLayout, callback) == 80, "represented field offset");
static_assert(sizeof(FieldLeafa15680) == sizeof(ResearchLayouts::NativeFunctionLayout), "source container adds no storage");
