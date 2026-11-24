// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// RVA 0x340b80, 93 bytes: TESGlobal scalar deleting destructor; the inline destructor calls ClearData and destroys the editor ID, then the out-of-line TESForm destructor runs.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesglobal.cpp (TESGlobal::~TESGlobal)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESGlobal.cpp (TESGlobal::~TESGlobal)
// Code origin: original reconstruction from the pinned image listing; the ClearData call order adapted from the sibling sources named above
// Adapted bodies: TESGlobal::~TESGlobal calls TESForm::ClearData first, as both sibling destructors do.
// CI hash: 0x340b80 ??_GTESGlobal@@UEAAPEAXI@Z
#include "TESGlobal_340b80.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
TESGlobal::TESGlobal()
{
}
