// Source exposure: mixed (binary-analysis shape; sibling-similar link body).
// Code origin: reconstruction from pinned-image observations; the LinkObject body resembles the cited permitted sibling body.
// Adapted bodies: BSProceduralLightningController::LinkObject (fo4-private@1b765c70 src/BSMain/BSProceduralLightningController.cpp:274), listed in the header.
// Sibling source: fo4-private@1b765c70 src/BSMain/BSProceduralLightningController.cpp:274
// SPDX-License-Identifier: CC0-1.0
// BSProceduralLightningController: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSProceduralLightningController::LinkObject: CRASHLOGGER_PDB(59818@2026.10.24)
// LinkObject: SIBLING(fo4-private@1b765c70, author-permission); loop-and-link shape, target-side member names and stream calls differ
// 0xffc880 BSProceduralLightningController::LinkObject
#include "BSProceduralLightningController_ffc880.h"

// Link the base controller, all nine interpolator slots, and the target object smart pointer.
void BSProceduralLightningController::LinkObject(NiStream& a_stream)
{
    NiTimeController::LinkObject(a_stream);

    for (std::uint16_t i = 0; i < 9; ++i) {
        SetInterpolator(a_stream.ReadLinkID(), i);
    }

    targetObject = a_stream.ReadLinkID();
}
