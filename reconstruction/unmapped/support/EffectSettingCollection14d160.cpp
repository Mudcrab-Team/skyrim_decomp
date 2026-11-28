// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x14d160 EffectSettingCollection14d160::SortByName
// Adapted bodies: none
#include "EffectSettingCollection14d160.h"

#include <cstring>

// PDB: the CrashLogger PDB names this EffectSettingCollection::SortByName; EffectSettingCollection14d160 is a stand-in for EffectSettingCollection with a partial layout.
// Compares two items lexicographically by their inherited name component.
int EffectSettingCollection14d160::SortByName(const NamedItem14d160* lhs, const NamedItem14d160* rhs)
{
    const char* rhsName = rhs->GetName();
    const char* lhsName = lhs->GetName();
    return std::strcmp(lhsName, rhsName);
}
