// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock1216b0: GUESS(low) STANDIN; original owner is unknown
// 0x1216b0 Unlock1216b0::~Unlock1216b0
#include "Unlock1216b0.h"

Unlock1216b0::~Unlock1216b0() {
    heap->Free(this);
}
