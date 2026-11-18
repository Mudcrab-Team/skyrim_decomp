// Code origin: declarations extended by hand from the local listings; names follow the community headers.
// Source exposure: mixed
// names: GUESS(low); names and signatures are hypotheses.
// TESLevCharacter, TESLeveledList, TESBoundAnimObject, TESBoundObject: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESLevCharacter.h, include/RE/T/TESLeveledList.h, include/RE/T/TESBoundAnimObject.h and include/RE/T/TESBoundObject.h.
// TESForm: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESForm.h and include/RE/B/BaseFormComponent.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESLevCharacter::UnClone3D, TESLevCharacter::SaveGame: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); names only, the bodies are written from the target listing
// UnClone3D return type: GUESS(low); the listing zeroes EAX, the community declaration returns void
// TESLeveledList::SaveGame: GUESS(low); address 0x1ea3a0, called on the base subobject at offset 0x30
#pragma once
class TESForm;
class BGSSaveFormBuffer;
class TESObjectREFR;
class BGSLoadGameBuffer { public: virtual ~BGSLoadGameBuffer(); void* buffer; unsigned long long unknown; unsigned int field18, field1c, field20, position; };
struct BGSLoadFormData { unsigned int formID, size, uncompressedSize, reserved; TESForm* form; unsigned int changeFlags, oldChangeFlags; };
class BGSLoadFormBuffer : public BGSLoadGameBuffer, public BGSLoadFormData {};
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESForm : public BaseFormComponent { public: void SaveGame(BGSSaveFormBuffer*); void LoadGame(BGSLoadFormBuffer*); void Revert(BGSLoadFormBuffer*); void* sourceFiles; unsigned int formFlags; unsigned int formID; unsigned short inGameFormFlags; unsigned char formType; };
struct ShortPoint3 { short x,y,z; }; struct BoundData { ShortPoint3 minimum, maximum; };
class TESBoundObject : public TESForm { public: BoundData bounds; };
class TESBoundAnimObject : public TESBoundObject {};
class TESLeveledList : public BaseFormComponent { public: void SaveGame(BGSSaveFormBuffer*); void LoadGame(BGSLoadFormBuffer*); void Revert(BGSLoadFormBuffer*); };
class TESLevCharacter : public TESBoundAnimObject, public TESLeveledList { public: unsigned int UnClone3D(TESObjectREFR*); void SaveGame(BGSSaveFormBuffer*); void LoadGame(BGSLoadFormBuffer*); void Revert(BGSLoadFormBuffer*); };
