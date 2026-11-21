// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation using the observed cleanup and partial layouts.
// NiSpotLight: GUESS(low)
// NiLight: STANDIN GUESS(low)
#pragma once

#include <cstdint>

class NiLight
{
public:
    virtual ~NiLight();

private:
    std::uint8_t padding08[0x138];
};

class NiSpotLight : public NiLight
{
public:
    NiSpotLight();
    ~NiSpotLight() override = default;

private:
    std::uint8_t padding140[0x28];
};
static_assert(sizeof(NiSpotLight) == 0x168, "observed allocation size");
