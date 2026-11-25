// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0x822b60 InterpolatorLeaf822b60::~InterpolatorLeaf822b60
#include "InterpolatorLeaf822b60_822b60.h"
#include <intrin.h>


LeafBase822b60::~LeafBase822b60()
{
    // The reference-object counter is updated atomically.
    _InterlockedDecrement(&gCount822b60);
}

InterpolatorLeaf822b60::InterpolatorLeaf822b60() = default;
InterpolatorLeaf822b60::~InterpolatorLeaf822b60() = default;
