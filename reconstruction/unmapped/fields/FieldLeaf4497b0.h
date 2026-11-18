// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf4497b0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "AIWorldInteriorCellLayout.h"
class FieldLeaf4497b0 : public ResearchLayouts::AIWorldInteriorCellLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::AIWorldInteriorCellLayout, point) == 16, "represented field offset");
static_assert(sizeof(FieldLeaf4497b0) == sizeof(ResearchLayouts::AIWorldInteriorCellLayout), "source container adds no storage");
