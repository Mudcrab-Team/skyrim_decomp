// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x1246900 PathFollowerStateTurnToAngle::SetParameters
// CI hash: 0x1246900 ?SetParameters@PathFollowerStateTurnToAngle@@QEAAXAEBUTurnToAngleParams@@@Z
#include "PathFollowerStateTurnToAngle_1246900.h"

// Copy turn-to-angle target parameters into the path follower state.
// The CrashLogger name is sub_14112EA60; the name used here is a guess from what the body does.
void PathFollowerStateTurnToAngle::SetParameters(const TurnToAngleParams& a_params)
{
    unk08 = a_params.unk00;
    unk18 = a_params.unk10;
    unk0C = a_params.unk04;
    unk10 = a_params.unk08;
    unk14 = a_params.unk0C;
    unk1C = a_params.unk14;
}
