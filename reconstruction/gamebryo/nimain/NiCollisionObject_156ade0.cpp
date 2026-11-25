// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; body reconstructed from local target observations
// SPDX-License-Identifier: CC0-1.0
// 0x156ade0 NiCollisionObject::RegisterStreamables
// NiCollisionObject::RegisterStreamables: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
#include "NiCollisionObject_156ade0.h"

bool NiCollisionObject::RegisterStreamables(NiStream& stream)
{
    if (!NiObject::RegisterStreamables(stream)) {
        return false;
    }
    if (sceneObject) {
        sceneObject->RegisterStreamables(stream);
    }
    return true;
}
