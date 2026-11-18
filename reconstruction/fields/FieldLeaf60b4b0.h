// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf60b4b0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "ScalarCaptureCallableLayout.h"
class FieldLeaf60b4b0 : public ResearchLayouts::ScalarCaptureCallableLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::ScalarCaptureCallableLayout, callable) == 8, "represented field offset");
static_assert(sizeof(FieldLeaf60b4b0) == sizeof(ResearchLayouts::ScalarCaptureCallableLayout), "source container adds no storage");
