// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x418510 Sky::GetResult
// Adapted bodies: none
#include "Sky_418510.h"
void* Sky::GetResult() const
{
    SkyRoot* outer = root;
    if (!outer) return nullptr;
    SkyInner* inner = outer->inner;
    if (!inner) return nullptr;
    auto getLevel = [](SkyInner* object) { return object->level; };
    SkyLevel* level = getLevel(inner);
    return level ? level->result : nullptr;
}
