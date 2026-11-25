// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// PlayerCharacter: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function751810: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

class PlayerCharacter;
// defaultAmount751810, multiplier751810, AdjustPlayerValue: GUESS(low); player-value defaults and adjustment
extern float defaultAmount751810;
extern float multiplier751810;
extern "C" void AdjustPlayerValue(unsigned, PlayerCharacter*, float*);

class PlayerCharacter
{
public:
    std::uint8_t unknown00[0xae4];
    float amount;

    void Function751810(float value);
};
