// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeaf83b9d0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout. Stamped as a twin of matched 0x11b510 (unmapped/fields/FieldLeaf11b510): source copied, names replaced by placeholders.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "BoundPairCallableLayout.h"

class FieldLeaf83b9d0 : public ResearchLayouts::BoundPairCallableLayout {
public:
    const void* Read();
};

static_assert(sizeof(FieldLeaf83b9d0) == sizeof(ResearchLayouts::BoundPairCallableLayout), "source container adds no storage");
