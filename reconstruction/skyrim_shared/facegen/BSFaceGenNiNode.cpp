// Source exposure: mixed (pinned image listing, sibling hint, community declarations).
// Code origin: existing sibling-adapted method plus original reconstruction of Function43d080.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/FaceGen/BSFaceGenNiNode.cpp:156
// Adapted bodies: UpdateDownwardPass from fo4-private@1b765c70; Function43d080 original.
// 0x439650 BSFaceGenNiNode::UpdateDownwardPass
// 0x43d080 BSFaceGenNiNode::Function43d080
// BSFaceGenNiNode::UpdateDownwardPass: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(tesv-2013-map)
#include "BSFaceGenNiNode.h"
void BSFaceGenNiNode::UpdateDownwardPass(NiUpdateData& data, unsigned flagsValue) { if ((flags & 1) == 0) UpdateMorphing(data); NiNode::UpdateDownwardPass(data, flagsValue); }
void BSFaceGenNiNode::Function43d080() { bool flag = true; Helper43d930(&flag); }
