// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSMultiIndexTriShape: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1574f90: GUESS(low); provisional member name
// 0x1574f90 BSMultiIndexTriShape::Function1574f90
// CI hash: 0x1574f90 ?Function1574f90@BSMultiIndexTriShape@@QEAAXPEAV1@@Z
#include "BSMultiIndexTriShape_1574f90.h"

// Guess: Copy the base geometry and share its indexed resource range.
void BSMultiIndexTriShape::Function1574f90(BSMultiIndexTriShape* other)
{
    CopyBase(other);
    if (other->resource) { manager1574f90.Release(other->resource); }
    if (resource) { manager1574f90.Retain(resource); }
    other->resource = resource;
    other->count = count;
    other->range = range;
}
