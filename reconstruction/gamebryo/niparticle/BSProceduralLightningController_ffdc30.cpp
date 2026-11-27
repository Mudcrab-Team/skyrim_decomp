// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSProceduralLightningController: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSProceduralLightningController::sub_140D600C0: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xffdc30 BSProceduralLightningController::sub_140D600C0
#include "BSProceduralLightningController_ffdc30.h"

// Sample up to four float interpolators at the given time into their cached value slots.
void BSProceduralLightningController::sub_140D600C0(float a_time)
{
    if (interp0) {
        interp0->UpdateFloat(a_time, nullptr, value0);
    }
    if (interp1) {
        interp1->UpdateFloat(a_time, nullptr, value1);
    }
    if (interp2) {
        interp2->UpdateFloat(a_time, nullptr, value2);
    }
    if (interp3) {
        interp3->UpdateFloat(a_time, nullptr, value3);
    }
}
