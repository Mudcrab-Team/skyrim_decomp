// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// names: GUESS(low); names and signatures are hypotheses.
// BGSNote::InitializeData: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior to independently decoded target.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Character/BGSNote.cpp:41
// BGSNote, TESBoundObject, TESModel, TESFullName, TESIcon, BGSPickupPutdownSounds: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/B/BGSNote.h, include/RE/T/TESBoundObject.h, include/RE/T/TESModel.h, include/RE/T/TESFullName.h, include/RE/T/TESIcon.h and include/RE/B/BGSPickupPutdownSounds.h.
// TESForm: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESForm.h and include/RE/B/BaseFormComponent.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESForm : public BaseFormComponent { public: void* sourceFiles; unsigned int formFlags; unsigned int formID; unsigned short inGameFormFlags; unsigned char formType; };
struct ShortPoint3 { short x,y,z; }; struct BoundData { ShortPoint3 minimum, maximum; };
class TESBoundObject : public TESForm { public: BoundData bounds; };
class TESModel : public BaseFormComponent { public: const char* model; void* textures; void* addons; unsigned short textureCount; unsigned short addonCount; };
class TESFullName : public BaseFormComponent { public: const char* fullName; };
class TESIcon : public BaseFormComponent { public: const char* textureName; };
class BGSPickupPutdownSounds : public BaseFormComponent { public: void* pickupSound; void* putdownSound; };
class BGSNote : public TESBoundObject, public TESModel, public TESFullName, public TESIcon, public BGSPickupPutdownSounds { public:
 void InitializeData(); void* topic; void* actorBase; void* questList; void* questListNext; unsigned char type; bool hasBeenRead;
};
