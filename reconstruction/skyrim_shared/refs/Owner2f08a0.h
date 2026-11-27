// Source exposure: mixed
// Code origin: Stamped as a twin of matched 0x300c90 (skyrim_shared/refs/TESObjectREFR_2fd720): source copied, names replaced by placeholders.
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR_ExtraData.cpp:378
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR_Animation.cpp:71
// TESForm: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESForm.h, include/RE/T/TESObjectREFR.h and include/RE/B/BaseFormComponent.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Function2f08a0, Owner2f08a0: GUESS(low) STANDIN
#pragma once
#include "TESObjectREFR_2fd720.h"

class Owner2f08a0 : public TESForm, public BSHandleRefObject, public BSTEventSink, public IAnimationGraphManagerHolder { public:
 void Function2f08a0(ActorCause*); bool GetAnimationGraphManagerImpl(AnimationGraphPointer&) const;
 OBJ_REFR data; TESObjectCELL* parentCell; LOADED_REF_DATA* loadedData; ExtraDataList extraList;
};

