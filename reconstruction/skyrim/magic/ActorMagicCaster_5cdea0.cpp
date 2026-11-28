// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// ActorMagicCaster: CRASHLOGGER_PDB(59818@2026.10.24)
// GetSourcePositionForMagicProjectile: GUESS(low)
// 0x5cdea0 ActorMagicCaster::GetSourcePositionForMagicProjectile
#include "ActorMagicCaster_5cdea0.h"

// Computes the world-space launch position for a spell projectile.
// The CrashLogger name carries an address suffix, which is dropped here.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
void ActorMagicCaster::GetSourcePositionForMagicProjectile(NiPoint3* a_out, NiAVObject* a_node)
{
    if (a_node == nullptr)
    {
        a_node = GetCasterNode(false);
    }

    NiAVObject* magicNode = GetMagicNode();
    if (magicNode != nullptr)
    {
        a_out->x = magicNode->worldTranslate.x;
        a_out->y = magicNode->worldTranslate.y;
        a_out->z = magicNode->worldTranslate.z;
        Actor* caster = GetCasterAsActor();
        if (caster != nullptr)
        {
            caster->AdjustProjectileSource(a_out);
        }
    }
    else if (a_node != nullptr)
    {
        a_out->x = a_node->localTranslate.x;
        a_out->y = a_node->localTranslate.y;
        a_out->z = a_node->localTranslate.z;
    }
}
