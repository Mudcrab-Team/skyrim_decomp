// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// Adapted bodies: none
// 0xfb1530 NiPSysGrowFadeModifier::CopyMembers
#include "NiPSysGrowFadeModifier_fb1530.h"

// Copies base modifier members and grow/fade parameters into the destination modifier.
void NiPSysGrowFadeModifier::CopyMembers(NiPSysGrowFadeModifier* a_dest, NiCloningProcess& a_clone)
{
    NiPSysModifier::CopyMembers(a_dest, a_clone);
    a_dest->growTime = growTime;
    a_dest->growGeneration = growGeneration;
    a_dest->fadeTime = fadeTime;
    a_dest->fadeGeneration = fadeGeneration;
    a_dest->baseScale = baseScale;
}
