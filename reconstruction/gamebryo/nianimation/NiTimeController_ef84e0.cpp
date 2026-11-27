// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiTimeController: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiTimeController::StartAnimations: GUESS(low)
// 0xef84e0 NiTimeController::StartAnimations
#include "NiTimeController_ef84e0.h"

#include <cfloat>

// Recursively start all time controllers attached to an object, its geometry states, and child nodes.
void NiTimeController::StartAnimations(NiObjectNET* a_object)
{
    for (NiTimeController* ctrl = a_object->controllers; ctrl; ctrl = ctrl->next) {
        ctrl->Start(-FLT_MAX);
    }

    if (BSGeometry* geom = a_object->AsGeometry()) {
        if (geom->effectState && geom->effectState->controllers) {
            StartAnimations(geom->effectState);
        }
        if (geom->lightingProperty && geom->lightingProperty->controllers) {
            StartAnimations(geom->lightingProperty);
        }
    }

    if (a_object->AsNode()) {
        NiNode* node = static_cast<NiNode*>(a_object);
        for (std::uint32_t i = 0; i < node->childCapacity; ++i) {
            if (NiObjectNET* child = node->children[i]) {
                StartAnimations(child);
            }
        }
    }
}
