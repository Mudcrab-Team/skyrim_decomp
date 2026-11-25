// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESObjectREFR: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function302070: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

class TESObjectREFR;
// Extra302070: GUESS(low) STANDIN; reference-link extra data
struct Extra302070 { TESObjectREFR* GetNext(unsigned); };

class TESObjectREFR
{
public:
    std::uint8_t unknown00[0x70];
    Extra302070 extra;

    bool Function302070();
};
