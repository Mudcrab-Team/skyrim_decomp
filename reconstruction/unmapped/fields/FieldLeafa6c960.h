// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeafa6c960, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "ScalarCaptureCallableLayout.h"
class FieldLeafa6c960 : public ResearchLayouts::ScalarCaptureCallableLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::ScalarCaptureCallableLayout, callable) == 8, "represented field offset");
static_assert(sizeof(FieldLeafa6c960) == sizeof(ResearchLayouts::ScalarCaptureCallableLayout), "source container adds no storage");
