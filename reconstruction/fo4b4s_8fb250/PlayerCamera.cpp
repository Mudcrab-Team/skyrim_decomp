// CreateRefHandle: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); output parameter declaration adapted from include/RE/M/Misc.h; target callee identity remains inferred.
// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// PlayerCamera::SetCameraTarget: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/PlayerCamera.cpp:272
// PlayerCamera, TESCamera, BSHandleRefObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/P/PlayerCamera.h, include/RE/T/TESCamera.h, include/RE/T/TESObjectREFR.h, include/RE/B/BSHandleRefObject.h and include/RE/B/BSPointerHandle.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x8fb250 PlayerCamera::SetCameraTarget
#include "PlayerCamera.h"
void PlayerCamera::SetCameraTarget(Actor* actor) { if (actor) { if (!(actor->refCount & 0x3ff)) cameraTarget = nullHandle; else { unsigned bits; CreateRefHandle(bits, actor); cameraTarget = bits; } } }
