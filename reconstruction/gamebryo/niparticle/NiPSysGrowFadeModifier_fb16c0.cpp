// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: written from the listing and community PDB names; see Adapted bodies.
// Adapted bodies: WriteValue, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator.cpp:197
// 0xfb16c0 NiPSysGrowFadeModifier::SaveBinary
#include "NiPSysGrowFadeModifier_fb16c0.h"

// WriteValue: GUESS
template <class T>
static void WriteValue(NiBinaryStream* a_binary, const T& a_value)
{
    std::uint32_t componentSize = sizeof(T);
    a_binary->position += a_binary->write(a_binary, &a_value, sizeof(T), &componentSize, 1);
}

// Saves base modifier fields and grow/fade parameters to a stream.
void NiPSysGrowFadeModifier::SaveBinary(NiStream& a_stream)
{
    NiPSysModifier::SaveBinary(a_stream);
    WriteValue(a_stream.output, growTime);
    WriteValue(a_stream.output, growGeneration);
    WriteValue(a_stream.output, fadeTime);
    WriteValue(a_stream.output, fadeGeneration);
    WriteValue(a_stream.output, baseScale);
}
