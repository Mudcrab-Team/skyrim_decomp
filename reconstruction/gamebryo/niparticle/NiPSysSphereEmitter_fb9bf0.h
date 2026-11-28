// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// NiPSysSphereEmitter, IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysVolumeEmitter, NiObject, unk08, emitterRadius: GUESS(low) STANDIN
#pragma once

#include <cstdint>

class NiObject
{
public:
    virtual ~NiObject();
};

class NiPSysVolumeEmitter : public NiObject
{
public:
    bool IsEqual(NiObject* object);

    std::uint64_t unk08[14];  // 08
};
static_assert(sizeof(NiPSysVolumeEmitter) == 0x78, "NiPSysVolumeEmitter size");

class NiPSysSphereEmitter : public NiPSysVolumeEmitter
{
public:
    bool IsEqual(NiObject* object);

    float emitterRadius;  // 78
};
static_assert(sizeof(NiPSysSphereEmitter) == 0x80, "NiPSysSphereEmitter size");
