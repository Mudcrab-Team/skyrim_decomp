// Code origin: hand-written from the local listing; names and declarations from the community header named in BSCubeMapCamera.h.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0x1559a60 BSCubeMapCamera::RenderCubemap
#include "BSCubeMapCamera.h"

// RenderCubemapFaces: STANDIN GUESS(low); the worker called at address 0x1559ea0 with the same arguments
void RenderCubemapFaces(BSCubeMapCamera* a_camera, FaceEnableFlags a_faceMask, bool a_arg2, bool a_clearScenes, bool a_arg4);

void BSCubeMapCamera::RenderCubemap(FaceEnableFlags a_faceMask, bool a_arg2, bool a_clearScenes, bool a_arg4)
{
    RenderCubemapFaces(this, a_faceMask, a_arg2, a_clearScenes, a_arg4);
}
