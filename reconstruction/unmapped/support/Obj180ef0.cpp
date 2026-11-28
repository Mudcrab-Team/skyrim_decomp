// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x180ef0 Obj180ef0::IsNotEqual
// Adapted bodies: none.
#include "Obj180ef0.h"

// Compares lock state fields and computed difficulty ranks between two lock data holders.
bool Obj180ef0::IsNotEqual(const Obj180ef0* a_rhs) const
{
    const LockData180ef0* rhs = a_rhs->lock10;
    const LockData180ef0* lhs = lock10;
    if (lhs->flags10 != rhs->flags10) {
        return true;
    }
    if (lhs->key08 != rhs->key08) {
        return true;
    }
    if (lhs->GetDifficultyRank() != rhs->GetDifficultyRank()) {
        return true;
    }
    if (lhs->unk14 != rhs->unk14) {
        return true;
    }
    if (lhs->unk18 != rhs->unk18) {
        return true;
    }
    return false;
}
