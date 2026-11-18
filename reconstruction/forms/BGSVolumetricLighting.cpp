// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x263d40 BGSVolumetricLighting::~BGSVolumetricLighting
#include "BGSVolumetricLighting.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BGSVolumetricLighting::BGSVolumetricLighting()
{
}

// RVA 0x263cf0, 3 bytes: an empty slot body.
void BGSVolumetricLighting::ClearData()
{
}

// Empty inline-form destructor: the target stores the vftable and calls the base destructor itself (cookbook rule 4).
BGSVolumetricLighting::~BGSVolumetricLighting()
{
}
