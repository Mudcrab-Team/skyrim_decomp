// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// Adapted bodies: none
// 0x44d5e0 TaggedEntry44d5e0::DiffersFrom (inventory/PDB guess: Projectile::RemoveItem)
#include "TaggedEntry44d5e0.h"

// Return true if the other object does not cast to this type or differs in the upper 62 bits of field08.
bool TaggedEntry44d5e0::DiffersFrom(PolymorphicBase* other) const
{
    auto* rhs = dynamic_cast<TaggedEntry44d5e0*>(other);
    if (!rhs) {
        return true;
    }
    if (((rhs->field08 ^ field08) & ~3ull) != 0) {
        return true;
    }
    return false;
}
