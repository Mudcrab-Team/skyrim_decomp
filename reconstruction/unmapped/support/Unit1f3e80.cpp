// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1f3e80 Unit1f3e80::HasPrefix1f3e80
// Adapted bodies: none
#include "Unit1f3e80.h"

// PDB: the CrashLogger PDB name is Scaleform::GFx::AS3::Instances::fl_net::URLLoader::IsLoadingVariables; the stand-in name here is kept.
extern "C" __declspec(dllimport) int __cdecl _strnicmp(const char* a_lhs, const char* a_rhs, std::size_t a_count);

// Checks whether the first three characters of text match the fixed prefix.
bool Unit1f3e80::HasPrefix1f3e80() const
{
    return _strnicmp(text, g_prefix1f3e80, 3) == 0;
}
