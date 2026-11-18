// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf448e20, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "AIWorldPointRadiusLayout.h"
class FieldLeaf448e20 : public ResearchLayouts::AIWorldPointRadiusLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::AIWorldPointRadiusLayout, point) == 8, "represented field offset");
static_assert(sizeof(FieldLeaf448e20) == sizeof(ResearchLayouts::AIWorldPointRadiusLayout), "source container adds no storage");
