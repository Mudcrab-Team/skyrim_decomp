// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf97180 ExtraPostLinkLeaff97180::PostLinkObject
#include "ExtraPostLinkLeaff97180_f97180.h"
#include <intrin.h>

void ExtraPostLinkLeaff97180::PostLinkObject(ExtraStreamf97180& stream)
{
    ExtraPostBasef97180::PostLinkObject(stream);
    if (!owner) {
        return;
    }
    auto* replacement = owner->Find(&name);
    auto* old = value;
    if (old == replacement) {
        return;
    }
    if (replacement) {
        // Increment the new reference count atomically.
        _InterlockedIncrement(&replacement->count);
    }
    value = replacement;
    if (old) {
        // Decrement the previous reference count atomically.
    // The reference-object counter is updated atomically.
        if (_InterlockedDecrement(&old->count) == 0) {
            old->table->destroy(old);
        }
    }
}
