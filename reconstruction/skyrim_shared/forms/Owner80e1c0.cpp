// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; these bodies are written from the pinned image listing Stamped as a twin of matched 0x190a90 (skyrim_shared/forms/TESFullName_190a90): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// 0x80e1c0 Owner80e1c0::Function80e1c0
#include "Owner80e1c0.h"

// guess: same compiled code as matched 0x190a90 apart from relocated fields; its role here is not established.
const char* Owner80e1c0::Function80e1c0() const
{
    return GetFullName();
}

const char* Owner80e1c0::GetFullName() const
{
    return fullName.data();
}
