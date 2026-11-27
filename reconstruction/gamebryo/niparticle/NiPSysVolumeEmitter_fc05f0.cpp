// CI hash: 0xfc05f0 ??0NiPSysVolumeEmitter@@QEAA@XZ
// Source exposure: binary-analysis (pinned-image observations and image RTTI).
// Code origin: original constructor using the observed base-constructor boundary.
// SPDX-License-Identifier: CC0-1.0
// NiPSysVolumeEmitter, CtorBasefc05f0: STANDIN GUESS(low)
// 0xfc05f0 NiPSysVolumeEmitter::NiPSysVolumeEmitter
#include "NiPSysVolumeEmitter_fc05f0.h"

// Initialize the derived state after the base constructor.
NiPSysVolumeEmitter::NiPSysVolumeEmitter() : CtorBasefc05f0()
{
    volume = nullptr;
}
