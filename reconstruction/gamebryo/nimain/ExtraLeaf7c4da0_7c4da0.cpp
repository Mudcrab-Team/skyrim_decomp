// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0x7c4da0 ExtraLeaf7c4da0::~ExtraLeaf7c4da0
#include "ExtraLeaf7c4da0_7c4da0.h"
#include <intrin.h>


ExtraLeafBase::~ExtraLeafBase()
{
    // The reference-object counter is updated atomically.
    _InterlockedDecrement(&gExtraLeafCount);
}

ExtraLeaf7c4da0::ExtraLeaf7c4da0() = default;
ExtraLeaf7c4da0::~ExtraLeaf7c4da0() = default;
