// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeafb98910, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout. Stamped as a twin of matched 0x448e40 (unmapped/fields/FieldLeaf448e40): source copied, names replaced by placeholders.
// Origin: represented-field-leaf v3-labels2
#pragma once
#include "AIWorldPointRadiusLayout.h"

class FieldLeafb98910 : public ResearchLayouts::AIWorldPointRadiusLayout {
public:
    const void* Read();
};

static_assert(sizeof(FieldLeafb98910) == sizeof(ResearchLayouts::AIWorldPointRadiusLayout), "source container adds no storage");
