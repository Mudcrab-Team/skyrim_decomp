// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// Adapted bodies: none
// 0x44e6c0 ValueEntry44e6c0::CopyFrom (inventory/PDB guess: Projectile::Is3rdPersonVisible)
#include "ValueEntry44e6c0.h"

// Copy the 32-bit member at +0x10 from another instance if it dynamically casts to this type.
void ValueEntry44e6c0::CopyFrom(PolymorphicBase* other)
{
    if (auto* rhs = dynamic_cast<ValueEntry44e6c0*>(other)) {
        field10 = rhs->field10;
    }
}
