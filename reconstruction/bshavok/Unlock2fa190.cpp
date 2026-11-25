// Source exposure: mixed
// Code origin: Null-safe kind-of selection adapted from the cited Fallout: New Vegas sibling.
// names: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); null-safe kind-of selection adapted
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1397
// Unlock2fa190: GUESS(low) STANDIN; original owner is unknown
// Function2fa190: GUESS(low); provisional entry name
// 0x2fa190 Unlock2fa190::Function2fa190
#include "Unlock2fa190.h"

Body2fa190* Unlock2fa190::Function2fa190()
{
    auto* body = object;
    if (!body) return nullptr;
    return body->IsKindOfType(&rigidBodyType) ? body : nullptr;
}
