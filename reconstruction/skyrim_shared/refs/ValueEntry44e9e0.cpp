// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// Adapted bodies: none
// 0x44e9e0 ValueEntry44e9e0::DiffersFrom (inventory/PDB guess: Projectile::GetDecalGroup)
#include "ValueEntry44e9e0.h"

// Return true if the base tagged field differs or the other object does not match this derived 32-bit field.
bool ValueEntry44e9e0::DiffersFrom(PolymorphicBase* other) const
{
    if (TaggedBase44e9e0::IsBaseDifferent(other)) {
        return true;
    }
    auto* rhs = dynamic_cast<ValueEntry44e9e0*>(other);
    if (!rhs || field10 != rhs->field10) {
        return true;
    }
    return false;
}
