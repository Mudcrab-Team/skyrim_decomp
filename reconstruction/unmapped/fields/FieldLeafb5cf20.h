// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeafb5cf20, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout. Stamped as a twin of matched 0xef9b40 (unmapped/fields/FieldLeafef9b40): source copied, names replaced by placeholders.
// Origin: represented-field-leaf v1
#pragma once
#include "NiExtraDataLayout.h"

class FieldLeafb5cf20 : public ResearchLayouts::NiExtraDataLayout {
public:
    void* Read();
};

static_assert(sizeof(FieldLeafb5cf20) == sizeof(ResearchLayouts::NiExtraDataLayout), "source container adds no storage");
