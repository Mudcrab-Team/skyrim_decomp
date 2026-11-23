// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BSIsActiveModifier, UpdateFlagsCopied, bytes50, bytes51: GUESS(low); stand-in class view, members named by offset only
#pragma once
#include <cstdint>

class BSIsActiveModifier
{
public:
    void UpdateFlagsCopied();  // compared: 0xbb85a0

    std::uint8_t pad00[0x50];  // 00
    std::uint8_t flags[10];    // 50
};
