// Source exposure: mixed (represented declarations and local binary analysis).
// FieldLeafce8c60, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout. Stamped as a twin of matched 0x184b80 (unmapped/fields/FieldLeaf184b80): source copied, names replaced by placeholders.
// Origin: represented-field-leaf v1
#pragma once
#include "ExtraPoisonLayout.h"

class FieldLeafce8c60 : public ResearchLayouts::ExtraPoisonLayout {
public:
    void* Read();
};

static_assert(sizeof(FieldLeafce8c60) == sizeof(ResearchLayouts::ExtraPoisonLayout), "source container adds no storage");
