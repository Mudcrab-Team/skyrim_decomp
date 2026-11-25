// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// hkStringBuf: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionaae470: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// StringLength, stringAllocatorAae470: GUESS(low); string-length and allocator interfaces
extern "C" int StringLength(const char*);
extern unsigned char stringAllocatorAae470;

class hkStringBuf
{
public:
    void Insert(void*, int, const char*, int);

    void Functionaae470(int index, const char* text, int length);
};
