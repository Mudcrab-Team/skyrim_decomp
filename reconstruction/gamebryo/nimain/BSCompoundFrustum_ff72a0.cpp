// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSCompoundFrustum, planes, functionOperators, NiFrustumPlanes, BSCompoundFrustumOperator, BSTArrayHeapAllocator and BSTArrayBase: CRASHLOGGER_PDB(59818@2026.10.24)
// FrustumArray and Clear: GUESS(low)
// 0xff72a0 BSCompoundFrustum::~BSCompoundFrustum
// CI hash: 0xff72a0 ??1BSCompoundFrustum@@QEAA@XZ
#include "BSCompoundFrustum_ff72a0.h"

BSCompoundFrustum::~BSCompoundFrustum()
{
    planes.Clear();
    functionOperators.Clear();
}
