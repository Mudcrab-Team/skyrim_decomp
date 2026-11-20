// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// BGSBodyPartData::GetBodyPart, BGSBodyPartData::InitializeData: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Character/BGSBodyPartData.cpp:143
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Character/BGSBodyPartData.cpp:36
// BGSBodyPartData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/B/BGSBodyPartData.h, include/RE/T/TESForm.h, include/RE/T/TESModel.h and include/RE/B/BGSPreloadable.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
struct FileContainer { void* array; };
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESForm : public BaseFormComponent { public: FileContainer sourceFiles; unsigned formFlags, formID; unsigned short inGameFlags; unsigned char formType, pad; unsigned pad2; };
class TESModel : public BaseFormComponent { public: const char* model; void* textures; unsigned* addons; unsigned short numTextures, numAddons; unsigned pad; };
class BGSPreloadable : public BaseFormComponent {};
class BGSBodyPart;
class BGSRagdoll;
class BGSBodyPartData : public TESForm, public TESModel, public BGSPreloadable { public: BGSBodyPart* parts[6]; BGSRagdoll* ragdoll; BGSBodyPart* GetBodyPart(int type) const; void InitializeData(); };
