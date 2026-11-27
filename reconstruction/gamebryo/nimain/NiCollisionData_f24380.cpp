// Source exposure: mixed
// body: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); adapted body provenance only
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/fallout_shared/globalfunc_o2_variant.cpp:1121
// Code origin: adapted from the cited sibling body; local names remain provisional
// Adapted bodies: Functionf24380
// NiCollisionData: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionf24380: GUESS(low); provisional member name
// 0xf24380 NiCollisionData::Functionf24380
// CI hash: 0xf24380 ?Functionf24380@NiCollisionData@@QEAAPEAUNodef24380@@PEAU2@@Z
#include "NiCollisionData_f24380.h"

// Guess: Find the first ancestor carrying collision data.
Nodef24380* NiCollisionData::Functionf24380(Nodef24380* node)
{
    if (!node) {
        return nullptr;
    }
    Nodef24380* parent = node->parent;
    if (!parent) {
        return nullptr;
    }
    if (parent->collisionData) {
        return parent;
    }
    return Functionf24380(parent);
}
