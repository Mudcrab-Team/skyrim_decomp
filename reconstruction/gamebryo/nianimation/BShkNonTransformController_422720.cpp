// CI hash: 0x422720 ??_GBShkNonTransformController@@UEAAPEAXI@Z
// CI hash: 0x422c20 ??1BShkNonTransformController@@UEAA@XZ
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BShkNonTransformController: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// 0x422720 BShkNonTransformController::~BShkNonTransformController
// 0x422c20 BShkNonTransformController::~BShkNonTransformController
#include "BShkNonTransformController_422720.h"

// The out-of-line constructor emits the vftable and the scalar deleting destructor.
BShkNonTransformController::BShkNonTransformController() = default;

// Destroy the controller and release its target reference.
// CrashLogger PDB names 0x422c20 as a constructor. The body releases the target, so it is the destructor here.
BShkNonTransformController::~BShkNonTransformController() {}
