// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; these bodies are written from the pinned image listing Stamped as a twin of matched 0x190a90 (skyrim_shared/forms/TESFullName_190a90): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// 0x15a0910 Owner15a0910::Function15a0910
#include "Owner15a0910.h"

// guess: same compiled code as matched 0x190a90 apart from relocated fields; its role here is not established.
const char* Owner15a0910::Function15a0910() const
{
    return GetFullName();
}

const char* Owner15a0910::GetFullName() const
{
    return fullName.data();
}
