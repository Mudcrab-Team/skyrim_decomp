// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: NiAlphaAccumulator::~NiAlphaAccumulator, momusdigital/fnv_decomp@91e1b6e8
// 0xf0f290 NiAlphaAccumulator::IsEqual
// 0xf0f4a0 NiAlphaAccumulator::~NiAlphaAccumulator
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
