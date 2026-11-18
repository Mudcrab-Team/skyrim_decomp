// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// IronSightsState::GetRotation: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/IronSightsState.cpp:37
// TESCameraState, NiAVObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/T/TESCameraState.h, include/RE/N/NiAVObject.h, include/RE/N/NiObjectNET.h, include/RE/N/NiRefObject.h and include/RE/N/NiTransform.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x8f7970 IronSightsState::GetRotation
#include "IronSightsState.h"
void IronSightsState::GetRotation(NiQuaternion& out) const { if (cameraObject) out.FromRotation(cameraObject->world.rotation); else out = identityQuaternion; }
