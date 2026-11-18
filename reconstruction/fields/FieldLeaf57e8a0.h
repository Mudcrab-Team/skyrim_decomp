// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf57e8a0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "FunctionPointerCallableLayout.h"
class FieldLeaf57e8a0 : public ResearchLayouts::FunctionPointerCallableLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::FunctionPointerCallableLayout, callable) == 8, "represented field offset");
static_assert(sizeof(FieldLeaf57e8a0) == sizeof(ResearchLayouts::FunctionPointerCallableLayout), "source container adds no storage");
