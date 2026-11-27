// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: written from the listing and community PDB names; see Adapted bodies.
// Adapted bodies: WriteValue, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator.cpp:197
// NiPSysRotationModifier, NiPSysRotationModifier::SaveBinary_140D1FC60: CRASHLOGGER_PDB(59818@2026.10.24)
// NiBinaryStream, NiStream, NiPoint3, NiPoint3::SaveBinary, NiPSysModifier, NiPSysModifier::SaveBinary, vtable, position, unk0C, read, write, unk00, input, output, x, y, z, rotationSpeed, rotationSpeedVar, rotationAngle, rotationAngleVar, axis, randomAxis, randomRotSpeedSign: GUESS
#pragma once

#include <cstddef>
#include <cstdint>

class NiBinaryStream
{
public:
    void* vtable;
    std::uint32_t position;
    std::uint32_t unk0C;
    std::uint32_t (*read)(NiBinaryStream*, void*, std::uint32_t, std::uint32_t*, std::uint32_t);
    std::uint32_t (*write)(NiBinaryStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);
};

class NiStream
{
public:
    std::uint8_t unk00[0x298];
    NiBinaryStream* input;
    NiBinaryStream* output;
};

class NiPoint3
{
public:
    void SaveBinary(NiStream& a_stream) const;

    float x;
    float y;
    float z;
};

class NiPSysModifier
{
public:
    void SaveBinary(NiStream& a_stream);

    std::uint8_t unk00[0x30];
};

class NiPSysRotationModifier : public NiPSysModifier
{
public:
    void SaveBinary_140D1FC60(NiStream& a_stream);

    float rotationSpeed;
    float rotationSpeedVar;
    float rotationAngle;
    float rotationAngleVar;
    NiPoint3 axis;
    bool randomAxis;
    bool randomRotSpeedSign;
};

static_assert(offsetof(NiStream, output) == 0x2A0, "output offset");
static_assert(offsetof(NiPSysRotationModifier, axis) == 0x40, "axis offset");
static_assert(offsetof(NiPSysRotationModifier, randomAxis) == 0x4C, "randomAxis offset");
static_assert(offsetof(NiPSysRotationModifier, randomRotSpeedSign) == 0x4D, "randomRotSpeedSign offset");
