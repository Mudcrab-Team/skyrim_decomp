// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x3ee420 TESFullName::GetFullName_14038EE10
#include "TESFullName_3ee420.h"

// Return the form's full name string, falling back to its default table entry when empty.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
const char* TESFullName::GetFullName_14038EE10() const
{
    if (fullName.GetCStr() && *fullName.GetCStr()) {
        return fullName.GetCStr();
    }
    return gDefaultNames[defaultNameIndex].holder->name;
}
