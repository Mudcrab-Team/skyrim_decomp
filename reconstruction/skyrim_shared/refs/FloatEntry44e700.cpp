// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// Adapted bodies: none
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x44e700 FloatEntry44e700::DiffersFrom (inventory/PDB guess: Projectile::PopulateGraphProjectsToLoad)
#include "FloatEntry44e700.h"

// Return true if the base tagged field differs or the other object does not match this derived float field.
bool FloatEntry44e700::DiffersFrom(PolymorphicBase* other) const
{
    if (TaggedBase44e700::IsBaseDifferent(other)) {
        return true;
    }
    auto* rhs = dynamic_cast<FloatEntry44e700*>(other);
    if (!rhs || field10 != rhs->field10) {
        return true;
    }
    return false;
}
