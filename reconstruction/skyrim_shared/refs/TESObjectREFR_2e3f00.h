// Source exposure: mixed
// Code origin: original; local target observations and community declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BaseFormComponent, TESForm, TESBoundObject, TESObjectREFR: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN; minimal layout and virtual declarations.
// BSHandleRefObject, BSTEventSink, IAnimationGraphManagerHolder: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
// TESObjectREFR::Function2e3f00: GUESS(low); descriptive name unavailable.
#pragma once
class TESFile; class BGSSaveFormBuffer; class BGSLoadFormBuffer; class TESForm;
class BaseFormComponent { public: virtual ~BaseFormComponent(); virtual void InitializeDataComponent(); virtual void ClearDataComponent(); virtual void CopyComponent(BaseFormComponent*); };
class TESForm : public BaseFormComponent { public:
 virtual void InitializeData(); virtual void ClearData(); virtual bool Load(TESFile*); virtual bool LoadPartial(TESFile*); virtual bool LoadEdit(TESFile*); virtual TESForm* CreateDuplicateForm(bool,void*); virtual bool AddChange(unsigned int); virtual void RemoveChange(unsigned int); virtual bool FindInFileFast(TESFile*); virtual bool CheckSaveGame(BGSSaveFormBuffer*); virtual void SaveGame(BGSSaveFormBuffer*); virtual void LoadGame(BGSLoadFormBuffer*); virtual void InitLoadGame(BGSLoadFormBuffer*); virtual void FinishLoadGame(BGSLoadFormBuffer*); virtual void Revert(BGSLoadFormBuffer*); virtual void InitItemImpl(); virtual TESFile* GetDescriptionOwnerFile() const; virtual unsigned char GetSavedFormType() const; virtual void GetFormDetailedString(char*,unsigned int); virtual bool GetKnown() const; virtual bool GetRandomAnim() const; virtual bool GetPlayable() const; virtual bool IsHeadingMarker() const; virtual bool GetDangerous() const; virtual bool QHasCurrents() const; virtual bool GetObstacle() const; virtual bool QIsLODLandObject() const; virtual bool GetOnLocalMap() const; virtual bool GetMustUpdate() const; virtual void SetOnLocalMap(bool); virtual bool GetIgnoredBySandbox() const; virtual void SetDelete(bool); virtual void SetAltered(bool); virtual void SaveObjectBound(); virtual void LoadObjectBound(TESFile*); virtual bool IsBoundObject() const; virtual bool IsObject() const; virtual bool IsMagicItem() const; virtual bool IsWater() const;
 void* sourceFiles; unsigned int formFlags; unsigned int formID; unsigned short inGameFormFlags; unsigned char formType;
};
class TESBoundObject : public TESForm {};
class BSHandleRefObject { public: virtual ~BSHandleRefObject(); unsigned int refCount; };
class BSTEventSink { public: virtual ~BSTEventSink(); };
class IAnimationGraphManagerHolder { public: virtual ~IAnimationGraphManagerHolder(); };
class TESObjectREFR : public TESForm, public BSHandleRefObject, public BSTEventSink, public IAnimationGraphManagerHolder { public:
 bool Function2e3f00() const;
 TESBoundObject* objectReference;
};
