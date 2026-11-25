// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf5b190 TextKeyLeaff5b190::~TextKeyLeaff5b190
#include "TextKeyLeaff5b190_f5b190.h"
#include <intrin.h>

TextKeyLeafBase::~TextKeyLeafBase()
{
    // The reference-object counter is updated atomically.
    // The reference-object counter is updated atomically.
    _InterlockedDecrement(&gTextKeyLeafCount);
}

TextKeyLeaff5b190::TextKeyLeaff5b190() = default;
TextKeyLeaff5b190::~TextKeyLeaff5b190() = default;
