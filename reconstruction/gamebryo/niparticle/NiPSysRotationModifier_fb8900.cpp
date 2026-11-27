// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: written from the listing and community PDB names; see Adapted bodies.
// Adapted bodies: WriteValue, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator.cpp:197
// 0xfb8900 NiPSysRotationModifier::SaveBinary_140D1FC60
#include "NiPSysRotationModifier_fb8900.h"

// WriteValue: GUESS
template <class T>
static void WriteValue(NiBinaryStream* a_binary, const T& a_value)
{
    std::uint32_t componentSize = sizeof(T);
    a_binary->position += a_binary->write(a_binary, &a_value, sizeof(T), &componentSize, 1);
}

// WriteBool: GUESS
static void WriteBool(NiBinaryStream* a_binary, bool a_value)
{
    std::uint8_t byteValue = static_cast<std::uint8_t>(a_value);
    WriteValue(a_binary, byteValue);
}

// Saves base modifier fields and rotation parameters to a stream.
void NiPSysRotationModifier::SaveBinary_140D1FC60(NiStream& a_stream)
{
    NiPSysModifier::SaveBinary(a_stream);
    WriteValue(a_stream.output, rotationSpeed);
    WriteValue(a_stream.output, rotationSpeedVar);
    WriteValue(a_stream.output, rotationAngle);
    WriteValue(a_stream.output, rotationAngleVar);
    WriteBool(a_stream.output, randomRotSpeedSign);
    WriteBool(a_stream.output, randomAxis);
    axis.SaveBinary(a_stream);
}
