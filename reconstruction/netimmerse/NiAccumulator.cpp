// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none.
// 0xf1ede0 NiAccumulator::FinishAccumulating
// 0xf1ee00 NiAccumulator::~NiAccumulator
#include "NiAccumulator.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
NiAccumulator::NiAccumulator()
{
}

// TODO body: RVA 0xf1ede0, 9 bytes, NiAccumulator::FinishAccumulating.
void NiAccumulator::FinishAccumulating()
{
    unknown10 = 0;
}

// RVA 0xf0f4f0, 3 bytes: no group is started, so the result is null.
void* NiAccumulator::StartGroupingAlphas(NiBound*)
{
    return nullptr;
}

// RVA 0xf0f500, 3 bytes: an empty slot body.
void NiAccumulator::StopGroupingAlphas(void*)
{
}

// RVA 0xf1edd0, 5 bytes: stores the camera in the slot FinishAccumulating clears.
void NiAccumulator::StartAccumulating(NiCamera* a_camera)
{
    unknown10 = reinterpret_cast<std::uint64_t>(a_camera);
}

// Body done: RVA 0xf1ee00, 50 bytes, NiAccumulator::~NiAccumulator; compared as the scalar deleting
// destructor. The target does the NiRefObject cleanup itself, so keep this empty definition and the
// constructor: the inline base destructors in the header make the compiler produce the same body.
NiAccumulator::~NiAccumulator()
{
}
