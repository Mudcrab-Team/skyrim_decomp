// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaff43970, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "NiIntersectorFieldLayout.h"
class FieldLeaff43970 : public ResearchLayouts::NiIntersectorFieldLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::NiIntersectorFieldLayout, point30) == 48, "represented field offset");
static_assert(sizeof(FieldLeaff43970) == sizeof(ResearchLayouts::NiIntersectorFieldLayout), "source container adds no storage");
