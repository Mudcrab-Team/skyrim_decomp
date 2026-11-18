// Origin: adapted declarations from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT, include/RE/N/NiAVObject.h; body is original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xee0e90 NiAVObject::PreAttachUpdate
#include "NiAVObject.h"
void NiAVObject::PreAttachUpdate(NiNode* a_parent, NiUpdateData& a_data)
{
 parent = a_parent;
 UpdateDownwardPass(a_data, 0);
 parent = nullptr;
}
