// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// 0x1e8420 TESBoundObject::sub_140196DD0
// Adapted bodies: none
#include "TESBoundObject_1e8420.h"

// Dynamically casts this bound object to BoundObjectCastTarget and invokes virtual slot 4 if present.
void TESBoundObject::sub_140196DD0()
{
    if (auto* target = dynamic_cast<BoundObjectCastTarget*>(this)) {
        target->ClearObject();
    }
}
