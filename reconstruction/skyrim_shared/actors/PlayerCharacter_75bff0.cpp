// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x75bff0 PlayerCharacter::Func279_1406B45C0
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
#include "PlayerCharacter_75bff0.h"

// Add the player's position to a_out when the camera check is inactive and the actor node translation is zero.
void PlayerCharacter::Func279_1406B45C0(NiPoint3* a_out)
{
    if (!g_playerCamera75bff0->IsCameraActive()) {
        ActorNode75bff0* node = GetNode(true);
        if (node &&
            g_zeroPoint75bff0.x == node->unkA0.x &&
            g_zeroPoint75bff0.y == node->unkA0.y &&
            g_zeroPoint75bff0.z == node->unkA0.z) {
            a_out->x = unk54.x + a_out->x;
            a_out->y = unk54.y + a_out->y;
            a_out->z = unk54.z + a_out->z;
        }
    }
}
