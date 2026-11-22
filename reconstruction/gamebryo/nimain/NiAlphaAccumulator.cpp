// Source exposure: mixed (names and declarations from community headers; the listing of the pinned image).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0xf0f3b0 NiAlphaAccumulator::Functionf0f3b0
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
#include "NiAlphaAccumulator.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
NiAlphaAccumulator::NiAlphaAccumulator()
{
}

// TODO body: RVA 0xf0f290, 19 bytes, NiAlphaAccumulator::IsEqual.
bool NiAlphaAccumulator::IsEqual(NiObject* a_object)
{
    return NiBackToFrontAccumulator::IsEqual(a_object) != false;
}

// TODO body: RVA 0xf0f4a0, 62 bytes, NiAlphaAccumulator::~NiAlphaAccumulator; compared as the
// scalar deleting destructor. If the target calls a separate destructor, keep only the declaration
// and delete this definition (cookbook rule 18).
NiAlphaAccumulator::~NiAlphaAccumulator()
{
}

// NiAlphaAccumulator::Functionf0f3b0: GUESS(low)
void NiAlphaAccumulator::Functionf0f3b0()
{
    *reinterpret_cast<void**>(this) = &gAlphaStatic;
    return InitAlphaBase(this);
}
