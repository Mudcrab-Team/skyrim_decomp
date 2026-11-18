// Source exposure: mixed (local target analysis, public declarations and permitted sibling).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: GetObjectVoiceType body written from the local listing (returns null); the Clone3D and ReplaceModel bodies are adapted from the sibling forwarding cited below; declarations adapted from the community headers.
// Adapted bodies: Clone3D and ReplaceModel (sibling, see the Sibling source lines)
// names: GUESS(low); signatures and type names are hypotheses.
// TESBoundObject::Clone3D: SIBLING(fo4-private@1b765c70, author-permission); adapted virtual forwarding.
// TESBoundObject::ReplaceModel: SIBLING(fo4-private@1b765c70, author-permission); adapted virtual forwarding.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESObject.cpp:92
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESObject.cpp:105
// TESObject and TESBoundObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted declarations.
// 0x1467c0 TESBoundObject::GetObjectVoiceType
// 0x277e00 TESBoundObject::Clone3D
#include "TESBoundObject.h"
NiAVObject* TESBoundObject::Clone3D(TESObjectREFR* ref) { return Clone3D(ref, false); }
bool TESBoundObject::ReplaceModel() { return ReplaceModel(TESModel::GetModel(this)); }
BGSVoiceType* TESBoundObject::GetObjectVoiceType() const { return nullptr; }
