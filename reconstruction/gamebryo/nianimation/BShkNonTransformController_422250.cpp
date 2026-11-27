// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BShkNonTransformController: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BShkNonTransformController::Func1_1403C2120: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x422250 BShkNonTransformController::Func1_1403C2120
#include "BShkNonTransformController_422250.h"

// Copy the controller identifier from the init record and dispatch payload initialization.
bool BShkNonTransformController::Func1_1403C2120(NonTransformInitData* a_data)
{
    id = a_data->id;
    InitFromPayload(&a_data->payload, a_data->context);
    return true;
}
