// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: written from the listing and community PDB names; see Adapted bodies.
// Adapted bodies: ReadValue, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00a80000_o2.cpp:3546
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a80000_o2.cpp:3512
// NiPSysRotationModifier, NiPSysRotationModifier::LoadBinary_140D1FAD0: CRASHLOGGER_PDB(59818@2026.10.24)
// NiBinaryStream, NiStream, NiPoint3, NiPoint3::LoadFromStream, NiPSysModifier, NiPSysModifier::LoadBinary, vtable, position, unk0C, read, write, unk00, fileVersion, unk104, input, output, x, y, z, rotationSpeed, rotationSpeedVar, rotationAngle, rotationAngleVar, axis, randomAxis, randomRotSpeedSign: GUESS
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
    std::uint8_t unk00[0x100];
    std::uint32_t fileVersion;
    std::uint8_t unk104[0x194];
    NiBinaryStream* input;
    NiBinaryStream* output;
};

class NiPoint3
{
public:
    void LoadFromStream(NiStream& a_stream);

    float x;
    float y;
    float z;
};

class NiPSysModifier
{
public:
    void LoadBinary(NiStream& a_stream);

    std::uint8_t unk00[0x30];
};

class NiPSysRotationModifier : public NiPSysModifier
{
public:
    void LoadBinary_140D1FAD0(NiStream& a_stream);

    float rotationSpeed;
    float rotationSpeedVar;
    float rotationAngle;
    float rotationAngleVar;
    NiPoint3 axis;
    bool randomAxis;
    bool randomRotSpeedSign;
};

static_assert(offsetof(NiStream, fileVersion) == 0x100, "fileVersion offset");
static_assert(offsetof(NiStream, input) == 0x298, "input offset");
static_assert(offsetof(NiPSysRotationModifier, axis) == 0x40, "axis offset");
static_assert(offsetof(NiPSysRotationModifier, randomAxis) == 0x4C, "randomAxis offset");
static_assert(offsetof(NiPSysRotationModifier, randomRotSpeedSign) == 0x4D, "randomRotSpeedSign offset");
