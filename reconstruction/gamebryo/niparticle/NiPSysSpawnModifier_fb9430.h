// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: written from the listing and community PDB names; see Adapted bodies.
// Adapted bodies: WriteValue, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator.cpp:197
// NiPSysSpawnModifier, NiPSysSpawnModifier::SaveBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// NiBinaryStream, NiStream, NiPSysModifier, NiPSysModifier::SaveBinary, vtable, position, unk0C, read, write, unk00, input, output, numSpawnGenerations, unk32, percentageSpawned, minNumToSpawn, maxNumToSpawn, spawnSpeedChaos, spawnDirChaos, lifeSpan, lifeSpanVar: GUESS
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

class NiPSysModifier
{
public:
    void SaveBinary(NiStream& a_stream);

    std::uint8_t unk00[0x30];
};

class NiPSysSpawnModifier : public NiPSysModifier
{
public:
    void SaveBinary(NiStream& a_stream);

    std::uint16_t numSpawnGenerations;
    std::uint16_t unk32;
    float percentageSpawned;
    std::uint16_t minNumToSpawn;
    std::uint16_t maxNumToSpawn;
    float spawnSpeedChaos;
    float spawnDirChaos;
    float lifeSpan;
    float lifeSpanVar;
};

static_assert(offsetof(NiStream, output) == 0x2A0, "output offset");
static_assert(offsetof(NiPSysSpawnModifier, lifeSpanVar) == 0x48, "lifeSpanVar offset");
