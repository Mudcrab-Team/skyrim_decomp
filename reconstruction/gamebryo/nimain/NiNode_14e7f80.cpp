// Source exposure: mixed (binary-analysis, community headers).
// Origin: original reconstruction; types informed by CommonLibSSE-NG.
// NiNode: EXE_RTTI
// NiNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Function152a290, Function14e7f80, UpdateFloat, UpdateNode, localValue, localNode: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x152a290 NiNode::sub
// 0x14e7f80 NiNode::sub
#include "NiNode_14e7f80.h"
void NiNode::Function152a290(float value) { float localValue = value; UpdateFloat(&localValue); }
void NiNode::Function14e7f80(NiNode* node) { NiNode* localNode = node; UpdateNode(&localNode, this); }
