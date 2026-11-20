// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf14d6a50, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "AutoPropertyFunctionLayout.h"
class FieldLeaf14d6a50 : public ResearchLayouts::AutoPropertyFunctionLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::AutoPropertyFunctionLayout, objectName) == 16, "represented field offset");
static_assert(sizeof(FieldLeaf14d6a50) == sizeof(ResearchLayouts::AutoPropertyFunctionLayout), "source container adds no storage");
