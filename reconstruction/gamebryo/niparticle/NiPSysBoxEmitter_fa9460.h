// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// NiPSysBoxEmitter, NiPSysBoxEmitter::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject, NiPSysVolumeEmitter, NiPSysVolumeEmitter::IsEqual, emitterWidth, emitterHeight, emitterDepth, unk00: GUESS
#pragma once

#include <cstddef>
#include <cstdint>

class NiObject
{
};

class NiPSysVolumeEmitter : public NiObject
{
public:
    bool IsEqual(NiObject* a_other);

    std::uint8_t unk00[0x78];
};

class NiPSysBoxEmitter : public NiPSysVolumeEmitter
{
public:
    bool IsEqual(NiObject* a_other);

    float emitterWidth;
    float emitterHeight;
    float emitterDepth;
};

static_assert(sizeof(NiPSysVolumeEmitter) == 0x78, "NiPSysVolumeEmitter size");
static_assert(offsetof(NiPSysBoxEmitter, emitterWidth) == 0x78, "emitterWidth offset");
static_assert(offsetof(NiPSysBoxEmitter, emitterHeight) == 0x7C, "emitterHeight offset");
static_assert(offsetof(NiPSysBoxEmitter, emitterDepth) == 0x80, "emitterDepth offset");
