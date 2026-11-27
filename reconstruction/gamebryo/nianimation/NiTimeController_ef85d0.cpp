// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiTimeController: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiTimeController::StopAnimations: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xef85d0 NiTimeController::StopAnimations
#include "NiTimeController_ef85d0.h"

// Recursively stop all time controllers attached to an object, its geometry states, and child nodes.
void NiTimeController::StopAnimations(NiObjectNET* a_object)
{
    for (NiTimeController* ctrl = a_object->controllers; ctrl; ctrl = ctrl->next) {
        ctrl->Stop();
    }

    if (BSGeometry* geom = a_object->AsGeometry()) {
        if (geom->effectState && geom->effectState->controllers) {
            StopAnimations(geom->effectState);
        }
        if (geom->lightingProperty && geom->lightingProperty->controllers) {
            StopAnimations(geom->lightingProperty);
        }
    }

    if (a_object->AsNode()) {
        NiNode* node = static_cast<NiNode*>(a_object);
        for (std::uint32_t i = 0; i < node->childCapacity; ++i) {
            if (NiObjectNET* child = node->children[i]) {
                StopAnimations(child);
            }
        }
    }
}
