// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0x7c4fe0 ExtraLeaf7c4fe0::~ExtraLeaf7c4fe0
#include "ExtraLeaf7c4fe0_7c4fe0.h"
#include <intrin.h>


ExtraLeafBase7c4fe0::~ExtraLeafBase7c4fe0()
{
    // The reference-object counter is updated atomically.
    _InterlockedDecrement(&gExtraLeafCount7c4fe0);
}

ExtraLeaf7c4fe0::ExtraLeaf7c4fe0() = default;
ExtraLeaf7c4fe0::~ExtraLeaf7c4fe0() = default;
