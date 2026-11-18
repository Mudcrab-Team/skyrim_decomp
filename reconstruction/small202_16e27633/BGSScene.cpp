// Origin: adapted declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// BGSScene: EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x3a8980 BGSScene::Function3a8980
#include "BGSScene.h"
void BGSScene::Function3a8980(void* arg, std::uint32_t value) {
 SceneVisitor visitor{this, arg, value};
 actions.Apply(&visitor);
}
