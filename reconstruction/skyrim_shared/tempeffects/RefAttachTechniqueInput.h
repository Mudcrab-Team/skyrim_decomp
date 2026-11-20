// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// RefAttachTechniqueInput::Clear: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/BGSAttachTechniques.cpp:83
// RefAttachTechniqueInput: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/R/RefAttachTechniqueInput.h, include/RE/A/AttachTechniqueInput.h and include/RE/B/BSFixedString.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class TESObjectREFR; class TESRace; class bhkWorld;
class FixedString { public: void* data; FixedString& operator=(const FixedString&); static const FixedString& Empty(); };
class AttachTechniqueInput { public: virtual ~AttachTechniqueInput(); virtual void Clear(); void* current3DRoot; void* attachedArt; unsigned attachPoint, pad; };
class RefAttachTechniqueInput : public AttachTechniqueInput { public: TESObjectREFR* actor; TESRace* actorRace; bhkWorld* physicsWorld; unsigned collisionFilter, pad; FixedString nodeName; void Clear() override; };
