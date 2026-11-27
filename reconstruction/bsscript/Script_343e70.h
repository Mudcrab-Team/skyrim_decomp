// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// Script: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function343e70: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// scriptMode343e70: GUESS(low); thread-local script mode
extern __declspec(thread) bool scriptMode343e70;

class Script
{
public:
    void Execute(void*, void*, unsigned, bool);

    bool Function343e70(unsigned mode, void* first, void* second);
};
