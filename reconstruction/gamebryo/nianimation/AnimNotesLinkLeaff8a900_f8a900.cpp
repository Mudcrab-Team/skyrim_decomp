// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf8a900 AnimNotesLinkLeaff8a900::LinkObject
#include "AnimNotesLinkLeaff8a900_f8a900.h"
#include <intrin.h>

void AnimNotesLinkLeaff8a900::LinkObject(AnimStreamf8a900& stream)
{
    AnimNotesBasef8a900::LinkObject(stream);
    for (int index = 0; index < count; ++index) {
        values[index] = stream.GetLinkedObject();
        // Increment the new reference count atomically.
        _InterlockedIncrement(&values[index]->count);
    }
}
