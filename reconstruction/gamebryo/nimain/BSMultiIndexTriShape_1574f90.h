// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSMultiIndexTriShape: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1574f90: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>
#include <xmmintrin.h>

// Manager1574f90, manager1574f90: GUESS(low) STANDIN; shared geometry resource manager
struct Manager1574f90 { void Release(void*); void Retain(void*); };
extern Manager1574f90 manager1574f90;

class BSMultiIndexTriShape
{
public:
    std::uint8_t unknown00[0x160];
    void* resource;
    unsigned count;
    std::uint8_t unknown16c[0x50];
    struct Range { float values[4]; } range;
    void CopyBase(BSMultiIndexTriShape*);

    void Function1574f90(BSMultiIndexTriShape* other);
};
