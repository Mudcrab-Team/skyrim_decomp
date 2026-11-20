// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf266990, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v2
#pragma once
#include "ConcreteObjectFormFactoryLayout.h"
class FieldLeaf266990 : public ResearchLayouts::ConcreteObjectFormFactoryLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::ConcreteObjectFormFactoryLayout, _name) == 8, "represented field offset");
static_assert(sizeof(FieldLeaf266990) == sizeof(ResearchLayouts::ConcreteObjectFormFactoryLayout), "source container adds no storage");
