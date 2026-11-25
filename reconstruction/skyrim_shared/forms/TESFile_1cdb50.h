// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESFile: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1cdb50: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Record1cdb50, origin1cdb50: GUESS(low) STANDIN; file record header and seek origin
struct Record1cdb50 { unsigned type; unsigned size; unsigned fields[4]; };
extern unsigned origin1cdb50;

class TESFile
{
public:
    std::uint8_t unknown00[0x284];
    Record1cdb50 record;
    std::uint8_t unknown29c[12];
    unsigned offset;
    bool Prepare();
    void Seek(unsigned, unsigned);
    unsigned Read(void*, unsigned);

    unsigned Function1cdb50(unsigned char* output, unsigned capacity);
};
