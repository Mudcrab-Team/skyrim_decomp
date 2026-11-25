// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ParticleArrayFfc200: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionffc200: GUESS(low); provisional member name
// 0xffc200 ParticleArrayFfc200::Functionffc200
// CI hash: 0xffc200 ?Functionffc200@ParticleArrayFfc200@@QEAAXPEAXII@Z
#include "ParticleArrayFfc200_ffc200.h"

// Guess: Sort an array by recursive partitioning; the receiver is array storage rather than a particle-system object.
void ParticleArrayFfc200::Functionffc200(void* key, unsigned first, unsigned last)
{
    if (first < last) {
        do {
            unsigned pivot = Partition(key, first, last);
            if (pivot) { Functionffc200(key, first, pivot - 1); }
            if (pivot >= count - 1) { break; }
            first = pivot + 1;
        } while (first < last);
    }
}
