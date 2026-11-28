// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: implementation based on the pinned game build; see Adapted bodies.
// Adapted bodies: NiBinaryStreamfa6e60::Write4, treated as adapted: it has the shape of the stream WriteValue helper, for which the origin check reports similar sibling bodies (cited below, CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator.cpp:197
// SPDX-License-Identifier: CC0-1.0
// 0xfa6e60 NiPSysBombModifier::SaveBinary_140D0FA60
#include "NiPSysBombModifier_fa6e60.h"

// Serialize the bomb modifier base fields, target link, axis, and scalar parameters.
void NiPSysBombModifier::SaveBinary_140D0FA60(NiStreamfa6e60& a_stream)
{
    NiPSysModifierfa6e60::SaveBinary(a_stream);
    a_stream.SaveLinkID(bombObj);
    bombAxis.SaveBinary(a_stream);
    a_stream.ostr->Write4(&decay);
    a_stream.ostr->Write4(&deltaV);
    a_stream.ostr->Write4(&decayType);
    a_stream.ostr->Write4(&symmType);
}
