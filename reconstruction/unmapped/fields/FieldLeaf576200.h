// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf576200, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "FunctionPointerCallableLayout.h"
class FieldLeaf576200 : public ResearchLayouts::FunctionPointerCallableLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::FunctionPointerCallableLayout, callable) == 8, "represented field offset");
static_assert(sizeof(FieldLeaf576200) == sizeof(ResearchLayouts::FunctionPointerCallableLayout), "source container adds no storage");
