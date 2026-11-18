// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf12b18e0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "ScalarCaptureCallableLayout.h"
class FieldLeaf12b18e0 : public ResearchLayouts::ScalarCaptureCallableLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::ScalarCaptureCallableLayout, callable) == 8, "represented field offset");
static_assert(sizeof(FieldLeaf12b18e0) == sizeof(ResearchLayouts::ScalarCaptureCallableLayout), "source container adds no storage");
