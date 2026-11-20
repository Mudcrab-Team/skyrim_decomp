// Source exposure: mixed
// Bodies adapted from community sources: none; tools/check_origin.py is run by attempt.
// 0xf6cda0 NiInterpolator::~NiInterpolator
// 0xf6cd40 NiInterpolator::ResolveDependencies
// 0xf6cbd0 NiInterpolator::RegisterStreamables
// 0xf6ccf0 NiInterpolator::GetActiveTimeRange
// 0xf6cde0 NiInterpolator::GetRTTI
// 0xf6cd10 NiInterpolator::GetSequenceInterpolator
#include "NiInterpolator.h"

// RVA 0xf6cda0, 50 bytes: scalar deleting destructor; a constructor is defined so the vftable is emitted
NiInterpolator::NiInterpolator() {}

NiInterpolator::~NiInterpolator() {}

// RVA 0xf6cd40, 3 bytes
bool NiInterpolator::ResolveDependencies(NiAVObjectPalette*) { return true; }

// RVA 0xf6cbd0, 5 bytes: tail call into the base implementation
bool NiInterpolator::RegisterStreamables(NiStream& a_stream) { return NiObject::RegisterStreamables(a_stream); }

// RVA 0xf6ccf0, 8 bytes
void NiInterpolator::GetActiveTimeRange(float& a_beginKeyTime, float& a_endKeyTime) const
{
	a_beginKeyTime = 0.0f;
	a_endKeyTime = 0.0f;
}

// RVA 0xf6cde0, 8 bytes
const NiRTTI* NiInterpolator::GetRTTI() const { return &NiRTTI_NiInterpolator; }

NiBoolInterpolator* NiInterpolator::AsNiBoolInterpolator()
{
	return nullptr;
}

bool NiInterpolator::Update5(float, NiObjectNET*, float&)
{
	return false;
}

bool NiInterpolator::Update6(float, NiObjectNET*, bool&)
{
	return false;
}

// RVA 0xf6cd10, 35 bytes
NiInterpolator* NiInterpolator::GetSequenceInterpolator(float, float)
{
	NiInterpolator* clone = Clone();
	clone->SetUpDependencies();
	return clone;
}
