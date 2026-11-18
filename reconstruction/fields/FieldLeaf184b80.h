// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf184b80, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v1
#pragma once
#include "ExtraPoisonLayout.h"
class FieldLeaf184b80 : public ResearchLayouts::ExtraPoisonLayout {
public:
    void* Read();
};
static_assert(offsetof(ResearchLayouts::ExtraPoisonLayout, poison) == 16, "represented field offset");
static_assert(sizeof(FieldLeaf184b80) == sizeof(ResearchLayouts::ExtraPoisonLayout), "source container adds no storage");
