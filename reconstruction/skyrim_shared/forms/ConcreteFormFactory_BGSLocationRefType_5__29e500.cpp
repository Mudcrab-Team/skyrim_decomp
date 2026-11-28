// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// CI hash: 0x29e500 ??_GConcreteFormFactory_BGSLocationRefType_5_@@UEAAPEAXI@Z
// Adapted bodies: none
// 0x29e500 ConcreteFormFactory_BGSLocationRefType_5_::dtor_deleting
#include "ConcreteFormFactory_BGSLocationRefType_5__29e500.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
ConcreteFormFactory_BGSLocationRefType_5_::ConcreteFormFactory_BGSLocationRefType_5_() {}

// Unregister form type 5 from the factory table on destruction.
ConcreteFormFactory_BGSLocationRefType_5_::~ConcreteFormFactory_BGSLocationRefType_5_()
{
    UnregisterFormFactory(5);
}
