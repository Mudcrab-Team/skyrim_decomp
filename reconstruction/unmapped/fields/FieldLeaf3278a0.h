// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf3278a0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v2
#pragma once
#include "ConcreteFormFactoryLayout.h"
class FieldLeaf3278a0 : public ResearchLayouts::ConcreteFormFactoryLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::ConcreteFormFactoryLayout, _name) == 8, "represented field offset");
static_assert(sizeof(FieldLeaf3278a0) == sizeof(ResearchLayouts::ConcreteFormFactoryLayout), "source container adds no storage");
