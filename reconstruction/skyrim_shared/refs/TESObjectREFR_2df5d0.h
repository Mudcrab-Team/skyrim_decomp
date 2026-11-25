// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESObjectREFR: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function2df5d0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Base2df5d0, Classify2df5d0, Normalize2df5d0: GUESS(low) STANDIN; numeric reference-base query
struct Base2df5d0 { float Value(); };
extern "C" __declspec(dllimport) int Classify2df5d0(double);
extern "C" __declspec(dllimport) int Normalize2df5d0(double);

class TESObjectREFR
{
public:
    std::uint8_t unknown00[0x40];
    Base2df5d0* base;

    bool Function2df5d0(TESObjectREFR* other);
};
