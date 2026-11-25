// DeleteThis, DecRefCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Cookbook: 0x155a2c0 29
// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: none.
// BSCubeMapCamera, NiCamera, NiPointer, NiRefObject, BSShaderAccumulator, scenes, accumulator, secondAccumulator, unk1B0, silhouetteColor: CRASHLOGGER_PDB(59818@2026.10.24)
// SceneArray: GUESS(low)
// 0x155a2c0 BSCubeMapCamera::~BSCubeMapCamera
// CI hash: 0x155a2c0 ??_GBSCubeMapCamera@@UEAAPEAXI@Z
#include "BSCubeMapCamera_155a2c0.h"

// The compiler emits the scalar deleting entry with a size-aware release after member destruction.
BSCubeMapCamera::~BSCubeMapCamera() = default;
