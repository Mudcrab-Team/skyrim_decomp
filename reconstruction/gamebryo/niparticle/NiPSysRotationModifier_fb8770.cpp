// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: written from the listing and community PDB names; see Adapted bodies.
// Adapted bodies: ReadValue, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00a80000_o2.cpp:3546
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a80000_o2.cpp:3512
// 0xfb8770 NiPSysRotationModifier::LoadBinary_140D1FAD0
#include "NiPSysRotationModifier_fb8770.h"

// ReadValue: GUESS
template <class T>
static void ReadValue(NiBinaryStream* a_binary, T& a_value)
{
    std::uint32_t componentSize = sizeof(T);
    a_binary->position += a_binary->read(a_binary, &a_value, sizeof(T), &componentSize, 1);
}

// Loads base modifier fields and rotation parameters from a stream.
void NiPSysRotationModifier::LoadBinary_140D1FAD0(NiStream& a_stream)
{
    NiPSysModifier::LoadBinary(a_stream);
    ReadValue(a_stream.input, rotationSpeed);
    if (a_stream.fileVersion >= 0x14000002u)
    {
        ReadValue(a_stream.input, rotationSpeedVar);
        ReadValue(a_stream.input, rotationAngle);
        ReadValue(a_stream.input, rotationAngleVar);
        std::uint8_t flag;
        ReadValue(a_stream.input, flag);
        randomRotSpeedSign = (flag != 0);
    }
    std::uint8_t axisFlag;
    ReadValue(a_stream.input, axisFlag);
    randomAxis = (axisFlag != 0);
    axis.LoadFromStream(a_stream);
}
