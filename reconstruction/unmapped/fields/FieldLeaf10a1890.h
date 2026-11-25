// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf10a1890, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout. Stamped as a twin of matched 0x11b510 (unmapped/fields/FieldLeaf11b510): source copied, names replaced by placeholders.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "BoundPairCallableLayout.h"

class FieldLeaf10a1890 : public ResearchLayouts::BoundPairCallableLayout {
public:
    const void* Read();
};

static_assert(sizeof(FieldLeaf10a1890) == sizeof(ResearchLayouts::BoundPairCallableLayout), "source container adds no storage");
