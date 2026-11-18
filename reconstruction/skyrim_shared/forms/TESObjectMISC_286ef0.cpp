// Source exposure: mixed
// Origin: original reconstruction from target and anonymous sibling, community declarations.
// names: GUESS(low); names and signatures are hypotheses.
// TESObjectMISC::LoadGame: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESObjectMISC.cpp:241
// TESObjectMISC, TESForm, TESObject, TESBoundObject, TESFullName, TESModel, TESModelTextureSwap, TESTexture, TESIcon, TESValueForm, BaseFormComponent: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESObjectMISC.h, TESForm.h, TESObject.h, TESBoundObject.h, TESFullName.h, TESModel.h, TESModelTextureSwap.h, TESTexture.h, TESIcon.h, TESValueForm.h and include/RE/B/BaseFormComponent.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x286ef0 TESObjectMISC::LoadGame
#include "TESObjectMISC_286ef0.h"
void TESObjectMISC::LoadGame(BGSLoadFormBuffer* buffer) { TESForm::LoadGame(buffer); TESValueForm::LoadGame(buffer); }
