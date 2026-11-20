// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// TweenMenuCameraState::End: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/TweenMenuCameraState.cpp:37
// TweenMenuCameraState: COMMUNITY(powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944, GPL-3.0); declaration adapted from include/RE/T/TweenMenuCameraState.h.
// The declaration derived from powerof3/CommonLibSSE is GPL-3.0.
// PlayerCamera, TESCameraState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/P/PlayerCamera.h, include/RE/T/TESCamera.h, include/RE/T/TESCameraState.h and include/RE/B/BSTArray.h and include/RE/B/BSAtomic.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x8ff380 TweenMenuCameraState::End
#include "TweenMenuCameraState.h"
void TweenMenuCameraState::End() { static_cast<PlayerCamera*>(camera)->worldFOV = initialFOV; }
