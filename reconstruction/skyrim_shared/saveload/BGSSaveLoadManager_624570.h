// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BGSSaveLoadManager: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function624570: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Files624570: GUESS(low) STANDIN; save-file collection
struct Files624570 { bool Contains(const char*); void Remove(const char*); };

class BGSSaveLoadManager
{
public:
    std::uint8_t unknown00[0xd0];
    Files624570 files;
    void Process(const char*);

    void Function624570(const char* file);
};
