// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeafab01d0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout. Stamped as a twin of matched 0x145670 (unmapped/fields/FieldLeaf145670): source copied, names replaced by placeholders.
// Origin: represented-field-leaf v2
#pragma once
#include "ConcreteFormFactoryLayout.h"
class FieldLeafab01d0 : public ResearchLayouts::ConcreteFormFactoryLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::ConcreteFormFactoryLayout, _name) == 8, "represented field offset");
static_assert(sizeof(FieldLeafab01d0) == sizeof(ResearchLayouts::ConcreteFormFactoryLayout), "source container adds no storage");
