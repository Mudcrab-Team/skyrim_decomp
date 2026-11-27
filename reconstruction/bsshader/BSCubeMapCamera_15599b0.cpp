// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Cookbook: 0x15599b0 29
// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the pinned image.
// BSCubeMapCamera, NiCamera, NiPointer, NiRefObject, BSShaderAccumulator, scenes, accumulator, secondAccumulator, unk1B0, silhouetteColor: CRASHLOGGER_PDB(59818@2026.10.24)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// BSTArray, NiAVObject, NiColorA: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x15599b0 BSCubeMapCamera::~BSCubeMapCamera
// CI hash: 0x15599b0 ??1BSCubeMapCamera@@UEAA@XZ
#include "BSCubeMapCamera_15599b0.h"

// CrashLogger calls this entry ctor. It releases the members in reverse order, then destroys the camera base.
BSCubeMapCamera::~BSCubeMapCamera()
{
}
