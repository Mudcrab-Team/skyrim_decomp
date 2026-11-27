// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// NiPSysCylinderEmitter, NiPSysCylinderEmitter::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject, NiPSysVolumeEmitter, NiPSysVolumeEmitter::IsEqual, emitterRadius, emitterHeight, unk00: GUESS
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

class NiPSysCylinderEmitter : public NiPSysVolumeEmitter
{
public:
    bool IsEqual(NiObject* a_other);

    float emitterRadius;
    float emitterHeight;
};

static_assert(sizeof(NiPSysVolumeEmitter) == 0x78, "NiPSysVolumeEmitter size");
static_assert(offsetof(NiPSysCylinderEmitter, emitterRadius) == 0x78, "emitterRadius offset");
static_assert(offsetof(NiPSysCylinderEmitter, emitterHeight) == 0x7C, "emitterHeight offset");
