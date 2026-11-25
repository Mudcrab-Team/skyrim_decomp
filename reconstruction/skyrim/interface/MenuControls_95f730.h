// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// MenuControls: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function95f730: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>


class MenuControls
{
public:
    std::uint8_t unknown00[0x81];
    std::uint8_t unknown81;

    void Function95f730(std::uint8_t value);
};
