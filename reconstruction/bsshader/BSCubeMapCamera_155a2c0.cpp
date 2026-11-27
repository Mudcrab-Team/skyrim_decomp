// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Cookbook: 0x155a2c0 29
// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the pinned image.
// BSCubeMapCamera, NiCamera, NiPointer, NiRefObject, BSShaderAccumulator, scenes, accumulator, secondAccumulator, unk1B0, silhouetteColor: CRASHLOGGER_PDB(59818@2026.10.24)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// BSTArray, NiAVObject, NiColorA: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x155a2c0 BSCubeMapCamera::dtor_deleting
// CI hash: 0x155a2c0 ??_GBSCubeMapCamera@@UEAAPEAXI@Z
#include "BSCubeMapCamera_155a2c0.h"

// CrashLogger names the scalar deleting entry. MSVC emits it from this destructor
// and conditionally calls sized delete after the base and member destructors finish.
BSCubeMapCamera::~BSCubeMapCamera()
{
}
