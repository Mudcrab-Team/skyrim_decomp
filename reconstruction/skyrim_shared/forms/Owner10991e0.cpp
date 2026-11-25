// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; these bodies are written from the pinned image listing Stamped as a twin of matched 0x190a90 (skyrim_shared/forms/TESFullName_190a90): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// 0x10991e0 Owner10991e0::Function10991e0
#include "Owner10991e0.h"

// guess: same compiled code as matched 0x190a90 apart from relocated fields; its role here is not established.
const char* Owner10991e0::Function10991e0() const
{
    return GetFullName();
}

const char* Owner10991e0::GetFullName() const
{
    return fullName.data();
}
