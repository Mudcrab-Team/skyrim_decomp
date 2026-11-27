// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function157170: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Extra157170: GUESS(low) STANDIN; linked extra-data record
struct Extra157170 { std::uint64_t unknown00; Extra157170* next; };

class ExtraDataList
{
public:
    void Remove(Extra157170*, bool);
    void Add(Extra157170*);

    void Function157170(Extra157170* value, ExtraDataList* destination);
};
