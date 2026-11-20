// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation using the observed cleanup and partial layouts.
// NiPSysSpawnModifier: GUESS(low)
// NiPSysModifier: STANDIN GUESS(low)
#pragma once

#include <cstdint>

class NiPSysModifier
{
public:
    virtual ~NiPSysModifier();

private:
    std::uint8_t padding08[0x28];
};

class NiPSysSpawnModifier : public NiPSysModifier
{
public:
    NiPSysSpawnModifier();
    ~NiPSysSpawnModifier() override = default;

private:
    std::uint8_t padding30[0x20];
};
static_assert(sizeof(NiPSysSpawnModifier) == 0x50, "observed allocation size");
