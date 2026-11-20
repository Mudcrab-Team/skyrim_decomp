// Source exposure: mixed
// Code origin: IronSightsState::GetRotation was adapted from the anonymous fo4-private sibling as labelled (author permission); IronSightsState::GetCurrentPosition was written from the pinned image listing by Taylor Turner with Claude Sonnet 5.5 (first drafts by DeepSeek V4.1 Flash) with no adapted body; declarations from the pinned community headers.
// IronSightsState::GetRotation: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/IronSightsState.cpp:37
// TESCameraState, NiAVObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/T/TESCameraState.h, include/RE/N/NiAVObject.h, include/RE/N/NiObjectNET.h, include/RE/N/NiRefObject.h and include/RE/N/NiTransform.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x8f7970 IronSightsState::GetRotation
// 0x8f79a0 IronSightsState::GetCurrentPosition
#include "IronSightsState.h"
void IronSightsState::GetRotation(NiQuaternion& out) const { if (cameraObject) out.FromRotation(cameraObject->world.rotation); else out = identityQuaternion; }
void IronSightsState::GetCurrentPosition(NiPoint3& a_out) const
{
    NiAVObject* object = cameraObject;
    if (object) {
        a_out.x = object->world.translation.x;
        a_out.y = object->world.translation.y;
        a_out.z = object->world.translation.z;
    } else {
        a_out.x = identityPosition.x;
        a_out.y = identityPosition.y;
        a_out.z = identityPosition.z;
    }
}
