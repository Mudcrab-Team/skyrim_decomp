// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation using the observed cleanup and partial layouts.
// BSAudioListener: EXE_RTTI
#pragma once

#include <cstdint>

class BSAudioListener
{
public:
    BSAudioListener();
    virtual ~BSAudioListener();

private:
    std::uint8_t padding08[0x38];
};
static_assert(sizeof(BSAudioListener) == 0x40, "observed allocation size");
