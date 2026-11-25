// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// Actor: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function6a8460: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Process6a8460: GUESS(low) STANDIN; actor process state
struct Process6a8460 { std::uint8_t unknown00[0x137]; std::uint8_t flag; };

class Actor
{
public:
    std::uint8_t unknown00[0xf8];
    Process6a8460* process;
    void Update();

    int Function6a8460();
};
