// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// NiFloatsExtraDataPoint3Controller: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// NiFloatsExtraDataPoint3Controller: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Basef7d060: GUESS(low) STANDIN; base subobject with unobserved members
class Basef7d060
{
public:
    Basef7d060(void*);
    virtual ~Basef7d060();
    std::uint8_t unknown08[88];
};

class NiFloatsExtraDataPoint3Controller : public Basef7d060
{
public:
    unsigned index;
    std::uint64_t* value;

     NiFloatsExtraDataPoint3Controller(void* source, unsigned element);
};
