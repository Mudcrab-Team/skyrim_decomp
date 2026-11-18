// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeafef9b40, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v1
#pragma once
#include "NiExtraDataLayout.h"
class FieldLeafef9b40 : public ResearchLayouts::NiExtraDataLayout {
public:
    void* Read();
};
static_assert(offsetof(ResearchLayouts::NiExtraDataLayout, name) == 16, "represented field offset");
static_assert(sizeof(FieldLeafef9b40) == sizeof(ResearchLayouts::NiExtraDataLayout), "source container adds no storage");
