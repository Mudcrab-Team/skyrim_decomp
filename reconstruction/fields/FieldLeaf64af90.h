// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf64af90, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "ScalarCaptureCallableLayout.h"
class FieldLeaf64af90 : public ResearchLayouts::ScalarCaptureCallableLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::ScalarCaptureCallableLayout, callable) == 8, "represented field offset");
static_assert(sizeof(FieldLeaf64af90) == sizeof(ResearchLayouts::ScalarCaptureCallableLayout), "source container adds no storage");
