// Source exposure: mixed (binary-analysis, community headers).
// Origin: original reconstruction; types informed by CommonLibSSE-NG.
// NiNode: EXE_RTTI
// NiNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Function152a290, Function14e7f80, UpdateFloat, UpdateNode, localValue, localNode: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class NiNode { public: void Function152a290(float value); void Function14e7f80(NiNode* node); void UpdateFloat(float* value); };
void UpdateNode(NiNode** value, NiNode* node);
