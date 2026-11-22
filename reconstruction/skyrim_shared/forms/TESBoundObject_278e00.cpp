// Source exposure: mixed (local target analysis, public declarations and permitted sibling).
// Origin: reconstructed from target and sibling hints.
// names: GUESS(low); signatures and type names are hypotheses.
// TESBoundObject::Clone3D: SIBLING(fo4-private@1b765c70, author-permission); adapted virtual forwarding.
// TESBoundObject::ReplaceModel: SIBLING(fo4-private@1b765c70, author-permission); adapted virtual forwarding.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESObject.cpp:92
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESObject.cpp:105
// TESObject and TESBoundObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x278e00 TESBoundObject::ReplaceModel
#include "TESBoundObject_278e00.h"
bool TESBoundObject::ReplaceModel() { return ReplaceModel(TESModel::GetModel(this)); }
