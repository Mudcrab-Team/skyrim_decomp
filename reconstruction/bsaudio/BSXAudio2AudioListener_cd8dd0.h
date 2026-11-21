// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation using the observed cleanup and partial layouts.
// BSXAudio2AudioListener: GUESS(low)
// BSAudioListener: STANDIN EXE_RTTI
#pragma once

#include <cstdint>

class BSAudioListener
{
public:
    virtual ~BSAudioListener() {}

private:
    std::uint8_t padding08[0x38];
};

class BSXAudio2AudioListener : public BSAudioListener
{
public:
    BSXAudio2AudioListener();
    ~BSXAudio2AudioListener() override = default;

private:
    std::uint8_t padding40[0x38];
};
static_assert(sizeof(BSXAudio2AudioListener) == 0x78, "observed allocation size");
