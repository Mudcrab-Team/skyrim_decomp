// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x52af40 TESWaterSystem::ResetWaterDisplacementSimulation
#include "TESWaterSystem_52af40.h"

void TESWaterSystem::ResetWaterDisplacementSimulation()
{
    unkD4 = 10.0f;
    simulation.Function52f8d0();
}
