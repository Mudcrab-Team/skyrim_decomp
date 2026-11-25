// Source exposure: binary-analysis
// Unlockef8b10: GUESS(low) STANDIN; original owner is unknown
// Functionef8b10: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
#include <xmmintrin.h>
struct Quaternionef8b10 { float w,x,y,z; };

class Unlockef8b10 {
public:
    static Quaternionef8b10* Functionef8b10(const Quaternionef8b10* input, Quaternionef8b10* out);
};

extern const __m128 quaternionConjugateSigns;
