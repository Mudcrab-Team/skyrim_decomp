// Source exposure: binary-analysis
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x442e40 FormFactory442e40::~FormFactory442e40
// CI hash: 0x442e40 ??_GFormFactory442e40@@UEAAPEAXI@Z
#include "FormFactory442e40_442e40.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
FormFactory442e40::FormFactory442e40()
{
}

// Unregister form type 0x5F when this form factory is destroyed.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
FormFactory442e40::~FormFactory442e40()
{
    UnregisterFormFactory(0x5F);
}
