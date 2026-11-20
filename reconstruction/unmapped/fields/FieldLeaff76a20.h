// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaff76a20, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout. Stamped as a twin of matched 0x4497b0 (unmapped/fields/FieldLeaf4497b0): source copied, names replaced by placeholders.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "AIWorldInteriorCellLayout.h"
class FieldLeaff76a20 : public ResearchLayouts::AIWorldInteriorCellLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::AIWorldInteriorCellLayout, point) == 16, "represented field offset");
static_assert(sizeof(FieldLeaff76a20) == sizeof(ResearchLayouts::AIWorldInteriorCellLayout), "source container adds no storage");
