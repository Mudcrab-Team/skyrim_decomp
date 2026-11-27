// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiObject::IncRefCount as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/niscreentexture.cpp:538
// SPDX-License-Identifier: CC0-1.0
// BSProceduralLightningController: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSProceduralLightningController::LinkObject: CRASHLOGGER_PDB(59818@2026.10.24)
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
