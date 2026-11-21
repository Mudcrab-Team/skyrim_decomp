// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// LocalMapCamera::~LocalMapCamera: SIBLING(fo4-private@1b765c70, author-permission); target wrapper uses independently observed behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/LocalMap.cpp:43
// LocalMapCamera, TESCamera: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/L/LocalMapCamera.h and include/RE/T/TESCamera.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x249f90 LocalMapCamera::~LocalMapCamera
// Code origin: original; the listing, community declarations and the CrashLogger PDB name only
// LocalMapCamera::SetMinFrustum: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x248270 LocalMapCamera::SetMinFrustum
// Adapted bodies: none
#include "LocalMapCamera.h"
static LocalMapCamera object;

void LocalMapCamera::SetMinFrustum(float a_width, float a_height)
{
    DefaultState* state = defaultState;
    state->minFrustumHalfWidth = a_width * 0.5f;
    state->minFrustumHalfHeight = a_height * 0.5f;
}
