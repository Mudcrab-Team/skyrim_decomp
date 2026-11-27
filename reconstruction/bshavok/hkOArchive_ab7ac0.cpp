// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// hkOArchive: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionab7ac0: GUESS(low); provisional member name
// 0xab7ac0 hkOArchive::Functionab7ac0
// CI hash: 0xab7ac0 ?Functionab7ac0@hkOArchive@@QEAAXN@Z
#include "hkOArchive_ab7ac0.h"

// Guess: Serialize one double through the archive interface.
void hkOArchive::Functionab7ac0(double value)
{
    Write(&value, 8, 1);
}
