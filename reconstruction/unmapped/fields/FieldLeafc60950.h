// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeafc60950, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout. Stamped as a twin of matched 0x448e40 (unmapped/fields/FieldLeaf448e40): source copied, names replaced by placeholders.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "AIWorldPointRadiusLayout.h"

class FieldLeafc60950 : public ResearchLayouts::AIWorldPointRadiusLayout {
public:
    const void* Read();
};

static_assert(sizeof(FieldLeafc60950) == sizeof(ResearchLayouts::AIWorldPointRadiusLayout), "source container adds no storage");
