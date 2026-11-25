// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BGSSaveLoadGame: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function617f20: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// ResolveForm: GUESS(low); form-identity resolver
extern "C" void* ResolveForm(unsigned);

class BGSSaveLoadGame
{
public:
    int Process(void*);

    int Function617f20(unsigned id);
};
