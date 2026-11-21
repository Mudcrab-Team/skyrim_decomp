// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf385860, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout. Stamped as a twin of matched 0x112670 (unmapped/fields/FieldLeaf112670): source copied, names replaced by placeholders.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "FunctionPointerCallableLayout.h"
class FieldLeaf385860 : public ResearchLayouts::FunctionPointerCallableLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::FunctionPointerCallableLayout, callable) == 8, "represented field offset");
static_assert(sizeof(FieldLeaf385860) == sizeof(ResearchLayouts::FunctionPointerCallableLayout), "source container adds no storage");
