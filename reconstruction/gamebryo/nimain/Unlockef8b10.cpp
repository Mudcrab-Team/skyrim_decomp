// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlockef8b10: GUESS(low) STANDIN; original owner is unknown
// Functionef8b10: GUESS(low); provisional entry name
// 0xef8b10 Unlockef8b10::Functionef8b10
#include "Unlockef8b10.h"

Quaternionef8b10* Unlockef8b10::Functionef8b10(const Quaternionef8b10* input, Quaternionef8b10* out)
{
    // Quaternion conjugation negates its vector part in parallel.
    auto components = _mm_loadu_ps(&input->w);
    // Sign changes preserve signed zero and NaN payloads.
    auto conjugate = _mm_xor_ps(components, quaternionConjugateSigns);
    // Unaligned storage supports quaternions embedded in packed objects.
    _mm_storeu_ps(&out->w, conjugate);
    return out;
}
