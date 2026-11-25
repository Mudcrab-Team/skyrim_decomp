// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESObjectREFR: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function2f3fc0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Point2f3fc0, Cell2f3fc0, Manager2f3fc0, manager2f3fc0, default2f3fc0: GUESS(low) STANDIN; reference cell relocation
struct Point2f3fc0 { float x; float y; float z; };
struct Cell2f3fc0 { void Add(unsigned*, unsigned); };
struct Manager2f3fc0 { Cell2f3fc0* Find(const Point2f3fc0*, bool*, unsigned); };
extern Manager2f3fc0* manager2f3fc0;
extern unsigned default2f3fc0;

class TESObjectREFR
{
public:
    std::uint8_t unknown00[0x28];
    unsigned references;
    std::uint8_t unknown2c[0x28];
    float position[3];
    Cell2f3fc0* cell;
    static void GetIdentity(unsigned*, const TESObjectREFR*);

    void Function2f3fc0();
};
