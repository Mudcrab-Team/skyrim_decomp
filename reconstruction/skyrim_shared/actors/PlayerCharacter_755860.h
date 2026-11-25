// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// PlayerCharacter: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function755860: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Form755860, Entry755860, Table755860: GUESS(low) STANDIN; player identity table insertion
struct Form755860 { std::uint8_t unknown00[0x14]; unsigned formID; };
struct Entry755860 { Entry755860* next; unsigned key; unsigned char value; };
struct Table755860 { virtual ~Table755860(); virtual unsigned Hash(unsigned); virtual bool Equal(unsigned,unsigned); virtual void Initialize(Entry755860*,unsigned,std::uint8_t); virtual void Unk04(); virtual Entry755860* Allocate(); std::uint64_t unknown08; Entry755860** buckets; unsigned count; };

class PlayerCharacter
{
public:
    std::uint8_t unknown00[0x618];
    Table755860 table;

    void Function755860(const Form755860* form, std::uint8_t value);
};
