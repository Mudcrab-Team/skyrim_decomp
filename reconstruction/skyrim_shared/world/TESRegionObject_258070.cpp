// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESRegionObject: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function258070: GUESS(low); provisional member name
// 0x258070 TESRegionObject::Function258070
// CI hash: 0x258070 ?Function258070@TESRegionObject@@QEAAXXZ
#include "TESRegionObject_258070.h"

// Guess: Propagate parent limits through the child region objects.
void TESRegionObject::Function258070()
{
    Link258070* item = children ? &children->first : nullptr;
    if (parent) {
        if (minimum < parent->minimum) { minimum = parent->minimum; }
        if (maximum > parent->maximum) { maximum = parent->maximum; }
    }
    while (item && item->object) {
        item->object->Function258070();
        item = item->next;
    }
}
