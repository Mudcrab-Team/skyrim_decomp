// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// names: GUESS(low); names and signatures are hypotheses.
// TESObjectREFR::GetDangerous: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// TESObjectREFR::GetRandomAnim: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// TESObjectREFR::GetObstacle: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR.cpp:160
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR.cpp:1378
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR.cpp:772
// TESForm, TESObjectREFR: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESForm.h, include/RE/T/TESObjectREFR.h and include/RE/B/BaseFormComponent.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class TESFile; class BGSSaveFormBuffer; class BGSLoadFormBuffer; class TESForm;
class BaseFormComponent { public: virtual ~BaseFormComponent(); virtual void InitializeDataComponent(); virtual void ClearDataComponent(); virtual void CopyComponent(BaseFormComponent*); };
class TESForm : public BaseFormComponent { public:
 virtual void InitializeData(); virtual void ClearData(); virtual bool Load(TESFile*); virtual bool LoadPartial(TESFile*); virtual bool LoadEdit(TESFile*); virtual TESForm* CreateDuplicateForm(bool,void*); virtual bool AddChange(unsigned int); virtual void RemoveChange(unsigned int); virtual bool FindInFileFast(TESFile*); virtual bool CheckSaveGame(BGSSaveFormBuffer*); virtual void SaveGame(BGSSaveFormBuffer*); virtual void LoadGame(BGSLoadFormBuffer*); virtual void InitLoadGame(BGSLoadFormBuffer*); virtual void FinishLoadGame(BGSLoadFormBuffer*); virtual void Revert(BGSLoadFormBuffer*); virtual void InitItemImpl(); virtual TESFile* GetDescriptionOwnerFile() const; virtual unsigned char GetSavedFormType() const; virtual void GetFormDetailedString(char*,unsigned int); virtual bool GetKnown() const; virtual bool GetRandomAnim() const; virtual bool GetPlayable() const; virtual bool IsHeadingMarker() const; virtual bool GetDangerous() const; virtual bool QHasCurrents() const; virtual bool GetObstacle() const;
 void* sourceFiles; unsigned int formFlags; unsigned int formID; unsigned short inGameFormFlags; unsigned char formType;
};
class TESBoundObject : public TESForm {};
class BSHandleRefObject { public: virtual ~BSHandleRefObject(); unsigned int refCount; };
class BSTEventSink { public: virtual ~BSTEventSink(); };
class IAnimationGraphManagerHolder { public: virtual ~IAnimationGraphManagerHolder(); };
class TESObjectREFR : public TESForm, public BSHandleRefObject, public BSTEventSink, public IAnimationGraphManagerHolder { public:
 bool GetDangerous() const override; bool GetRandomAnim() const override; bool GetObstacle() const override;
 TESBoundObject* objectReference;
};
