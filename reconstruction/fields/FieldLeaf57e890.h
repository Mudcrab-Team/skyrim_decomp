// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf57e890, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "FunctionPointerCallableLayout.h"
class FieldLeaf57e890 : public ResearchLayouts::FunctionPointerCallableLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::FunctionPointerCallableLayout, callable) == 8, "represented field offset");
static_assert(sizeof(FieldLeaf57e890) == sizeof(ResearchLayouts::FunctionPointerCallableLayout), "source container adds no storage");
