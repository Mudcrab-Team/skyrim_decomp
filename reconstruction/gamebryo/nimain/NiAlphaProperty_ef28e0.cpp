// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: implementation based on the pinned game build; see Adapted bodies.
// Adapted bodies: NiBinaryStream::Write, treated as adapted: it has the shape of the stream WriteValue helper, for which the origin check reports similar sibling bodies (cited below, CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator.cpp:197
// SPDX-License-Identifier: CC0-1.0
// 0xef28e0 NiAlphaProperty::SaveBinary
#include "NiAlphaProperty_ef28e0.h"

// Serialize base property fields followed by the alpha flags and threshold byte.
void NiAlphaProperty::SaveBinary(NiStream& a_stream)
{
    NiProperty::SaveBinary(a_stream);
    a_stream.ostr->Write(&flags, sizeof(flags), sizeof(flags));
    a_stream.ostr->Write(&alphaThreshold, sizeof(alphaThreshold), sizeof(alphaThreshold));
}
