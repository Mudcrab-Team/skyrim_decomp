// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// 0x1f82e0 BGSHavokGeometryAttach__AttachPolicy::Func1_1401A6880
// Adapted bodies: none
#include "BGSHavokGeometryAttach_1f82e0.h"

// Attaches Havok geometry to the entry's target when present and returns whether a target existed.
bool BGSHavokGeometryAttach::AttachPolicy::Func1_1401A6880(HavokAttachEntry* a_entry)
{
    HavokAttachTarget* target = a_entry->target;
    if (target) {
        target->Attach(a_entry->unk10, true, 0, a_entry->flags38, false);
        return true;
    }
    return false;
}
