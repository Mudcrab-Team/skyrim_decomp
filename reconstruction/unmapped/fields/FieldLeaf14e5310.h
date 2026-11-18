// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf14e5310, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v2
#pragma once
#include "ScriptBytecodeFunctionLayout.h"
class FieldLeaf14e5310 : public ResearchLayouts::ScriptBytecodeFunctionLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::ScriptBytecodeFunctionLayout, name) == 16, "represented field offset");
static_assert(sizeof(FieldLeaf14e5310) == sizeof(ResearchLayouts::ScriptBytecodeFunctionLayout), "source container adds no storage");
