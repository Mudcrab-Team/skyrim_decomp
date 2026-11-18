// Inferred names: GUESS(low)
// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefAttachTechniqueInput, BSFixedString, AttachTechniqueInput: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// actor, actorRace, physicsWorld, collisionFilter, pad3C, nodeName, current3DRoot, attachedArt, attachPoint: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Cleanup, ReleaseString, CleanupBase: GUESS(low); function and callee semantics inferred
#pragma once
#include <cstdint>
class NiNode; class TESObjectREFR; class TESRace; class bhkWorld;
class BSFixedString { public: void ReleaseString(); const char* data; };
namespace BSAttachTechniques { class AttachTechniqueInput { public: virtual ~AttachTechniqueInput(); virtual void Clear(); void CleanupBase(); NiNode* current3DRoot; NiNode* attachedArt; std::uint32_t attachPoint; std::uint32_t pad18; }; }
class RefAttachTechniqueInput : public BSAttachTechniques::AttachTechniqueInput { public: void Cleanup(); TESObjectREFR* actor; TESRace* actorRace; bhkWorld* physicsWorld; std::uint32_t collisionFilter; std::uint32_t pad3C; BSFixedString nodeName; };
