// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: written from the listing and community PDB names; see Adapted bodies.
// Adapted bodies: ReadValue, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00a80000_o2.cpp:3546
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a80000_o2.cpp:3512
// 0xfb1580 NiPSysGrowFadeModifier::LoadBinary
#include "NiPSysGrowFadeModifier_fb1580.h"

// ReadValue: GUESS
template <class T>
static void ReadValue(NiBinaryStream* a_binary, T& a_value)
{
    std::uint32_t componentSize = sizeof(T);
    a_binary->position += a_binary->read(a_binary, &a_value, sizeof(T), &componentSize, 1);
}

// Loads base modifier fields and grow/fade parameters from a stream.
void NiPSysGrowFadeModifier::LoadBinary(NiStream& a_stream)
{
    NiPSysModifier::LoadBinary(a_stream);
    ReadValue(a_stream.input, growTime);
    ReadValue(a_stream.input, growGeneration);
    ReadValue(a_stream.input, fadeTime);
    ReadValue(a_stream.input, fadeGeneration);
    ReadValue(a_stream.input, baseScale);
}
