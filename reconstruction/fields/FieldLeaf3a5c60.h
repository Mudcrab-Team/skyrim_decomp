// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf3a5c60, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v2
#pragma once
#include "ConcreteFormFactoryLayout.h"
class FieldLeaf3a5c60 : public ResearchLayouts::ConcreteFormFactoryLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::ConcreteFormFactoryLayout, _name) == 8, "represented field offset");
static_assert(sizeof(FieldLeaf3a5c60) == sizeof(ResearchLayouts::ConcreteFormFactoryLayout), "source container adds no storage");
