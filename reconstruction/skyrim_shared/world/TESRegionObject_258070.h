// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESRegionObject: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function258070: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

class TESRegionObject;
// Link258070, Children258070: GUESS(low) STANDIN; region-object list
struct Link258070 { TESRegionObject* object; Link258070* next; };
struct Children258070 { std::uint64_t unknown00; Link258070 first; };

class TESRegionObject
{
public:
    std::uint8_t unknown00[0x15];
    std::uint8_t minimum;
    std::uint8_t maximum;
    std::uint8_t unknown17[0x29];
    Children258070* children;
    TESRegionObject* parent;

    void Function258070();
};
