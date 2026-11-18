// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf32ae50, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v2
#pragma once
#include "ConcreteObjectFormFactoryLayout.h"
class FieldLeaf32ae50 : public ResearchLayouts::ConcreteObjectFormFactoryLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::ConcreteObjectFormFactoryLayout, _name) == 8, "represented field offset");
static_assert(sizeof(FieldLeaf32ae50) == sizeof(ResearchLayouts::ConcreteObjectFormFactoryLayout), "source container adds no storage");
