// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeafad9890, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout. Stamped as a twin of matched 0xf43970 (unmapped/fields/FieldLeaff43970): source copied, names replaced by placeholders.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "NiIntersectorFieldLayout.h"
class FieldLeafad9890 : public ResearchLayouts::NiIntersectorFieldLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::NiIntersectorFieldLayout, point30) == 48, "represented field offset");
static_assert(sizeof(FieldLeafad9890) == sizeof(ResearchLayouts::NiIntersectorFieldLayout), "source container adds no storage");
