// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// AIProcess: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function6ff270: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Point6ff270, High6ff270: GUESS(low) STANDIN; high-process vector
struct Point6ff270 { float x; float y; float z; Point6ff270& operator=(const Point6ff270& o) { x=o.x; y=o.y; z=o.z; return *this; } void Normalize(); };
struct High6ff270 { std::uint8_t unknown00[0x27c]; Point6ff270 point; };

class AIProcess
{
public:
    std::uint64_t unknown00;
    std::uint64_t unknown08;
    High6ff270* high;

    void Function6ff270(const Point6ff270& value);
};
