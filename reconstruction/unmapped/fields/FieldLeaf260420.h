// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf260420, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v2
#pragma once
#include "ConcreteFormFactoryLayout.h"
class FieldLeaf260420 : public ResearchLayouts::ConcreteFormFactoryLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::ConcreteFormFactoryLayout, _name) == 8, "represented field offset");
static_assert(sizeof(FieldLeaf260420) == sizeof(ResearchLayouts::ConcreteFormFactoryLayout), "source container adds no storage");
