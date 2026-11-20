// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation using the observed cleanup and partial layouts.
// BSXAudio2Audio: GUESS(low)
// BSAudio: STANDIN EXE_RTTI
#pragma once

#include <cstdint>

class BSAudio
{
public:
    virtual ~BSAudio() {}

private:
    std::uint8_t padding08[0x10];
};

class BSXAudio2Audio : public BSAudio
{
public:
    BSXAudio2Audio();
    ~BSXAudio2Audio() override = default;

private:
    std::uint8_t padding18[0x60];
};
static_assert(sizeof(BSXAudio2Audio) == 0x78, "observed allocation size");
