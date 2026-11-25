// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: Stamped as a twin of matched 0x3cd8d0 (skyrim_shared/actors/TESNPC): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Names and slot order follow CharmedBaryon/CommonLibSSE-NG b93280e (MIT): include/RE/T/TESNPC.h and the vftables of the pinned image; the powerof3 fork (GPL-3.0) declares the same names.
// BaseFormComponent, TESForm, TESBoundObject, TESActorBase: STANDIN EXE_RTTI COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT);
// BGSVoiceType, BGSRelationship, TESRace, HeadRelatedData, Sounds, FaceData, Layer, BSTArray: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Owner738110: GUESS(low) STANDIN
// Owner738110, Owner738110::~Owner738110, Owner738110::InitializeData, Owner738110::ClearData, Owner738110::Load, Owner738110::FindInFileFast, Owner738110::SaveGame, Owner738110::LoadGame, Owner738110::Revert, Owner738110::InitItemImpl, Owner738110::GetTextForParsedSubTag, Owner738110::Copy, Owner738110::Activate, Owner738110::UnClone3D, Owner738110::SetObjectVoiceType, Owner738110::GetObjectVoiceType, Owner738110::Clone3D_4A, Owner738110::GetActivateText, Owner738110::CalculateDoFavor, Owner738110::GetCombatStyle, Owner738110::SetCombatStyle, Owner738110::IsFemale, Owner738110::GetRelationshipRankIndex, Owner738110::GetScale, Owner738110::HasOverlays, unk150, race, unk160, headRelatedData, unk1D0, combatStyle, unk1E0, originalRace, unk1F0, height, unk1FC, sounds, unk208, relationships, faceData, tintLayers: GUESS(low) STANDIN
#pragma once
#include "TESNPC.h"

// Other RTTI bases (not declared here; their vftable pointers lie inside the members): .?AVTESActorBaseData@@, .?AVTESContainer@@, .?AVTESSpellList@@, .?AVTESAIForm@@, .?AVTESFullName@@, .?AVActorValueOwner@@, .?AVBGSDestructibleObjectForm@@, .?AVBGSSkinForm@@, .?AVBGSKeywordForm@@, .?AVBGSAttackDataForm@@, .?AVBGSPerkRankArray@@, .?AVTESRaceForm@@, .?AVBGSOverridePackCollection@@, .?AV?$BSTEventSink@VMenuOpenCloseEvent@@@@
class Owner738110 : public ::TESActorBase
{
public:
	// community declaration: virtual ~BaseFormComponent();
	~Owner738110() override;  // 00
	// community declaration: virtual void InitializeData();
	void InitializeData() override;  // 04
	// community declaration: virtual void ClearData();
	void ClearData() override;  // 05
	// community declaration: virtual bool Load(TESFile* a_mod);
	void Load() override;  // 06
	// community declaration: virtual bool FindInFileFast(TESFile* a_mod);
	void FindInFileFast() override;  // 0C
	// community declaration: virtual void SaveGame(BGSSaveFormBuffer* a_buf);
	void SaveGame() override;  // 0E
	// community declaration: virtual void LoadGame(BGSLoadFormBuffer* a_buf);
	void LoadGame() override;  // 0F
	// community declaration: virtual void Revert(BGSLoadFormBuffer* a_buf);
	void Revert() override;  // 12
	// community declaration: virtual void InitItemImpl();
	void InitItemImpl() override;  // 13
	// community declaration: [[nodiscard]] virtual const char* GetTextForParsedSubTag(const BSFixedString& a_tag) const;
	void GetTextForParsedSubTag() override;  // 2E
	// community declaration: virtual void Copy(TESForm* a_srcForm);
	void Copy() override;  // 2F
	// community declaration: virtual bool Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t
	void Activate() override;  // 37
	// community declaration: virtual void UnClone3D(TESObjectREFR* a_ref);
	void UnClone3D() override;  // 41
	// community declaration: virtual void SetObjectVoiceType(BGSVoiceType* a_voiceType);
	void SetObjectVoiceType(BGSVoiceType* a_voiceType) override;  // 48
	// community declaration: [[nodiscard]] virtual BGSVoiceType* GetObjectVoiceType() const;
	void GetObjectVoiceType() override;  // 49
	// community declaration: virtual NiAVObject* Clone3D(TESObjectREFR* a_ref);
	void Clone3D_4A() override;  // 4A
	// community declaration: virtual bool GetActivateText(TESObjectREFR* a_activator, BSString& a_dst);
	void GetActivateText() override;  // 4C
	// community declaration: virtual bool CalculateDoFavor(Actor* a_activator, bool a_arg2, TESObjectREFR* a_toActivate, float a_arg3);
	void CalculateDoFavor() override;  // 4D
	// community declaration: virtual TESCombatStyle* GetCombatStyle();
	TESCombatStyle* GetCombatStyle() override;  // 54
	// community declaration: virtual void SetCombatStyle(TESCombatStyle* a_combatStyle);
	void SetCombatStyle(TESCombatStyle* a_combatStyle) override;  // 55

	std::int32_t IsFemale();
	static std::int32_t GetRelationshipRankIndex(Owner738110* a_npc1, Owner738110* a_npc2);
	float GetScale();
	bool HasOverlays();

	std::uint8_t unk150[0x08];  // 150
	TESRace* race;  // 158
	std::uint8_t unk160[0x68];  // 160
	HeadRelatedData* headRelatedData;  // 1C8
	std::uint8_t unk1D0[0x8];  // 1D0
    TESCombatStyle* combatStyle;  // 1D8
    std::uint8_t unk1E0[0x8];  // 1E0
	TESRace* originalRace;  // 1E8
	std::uint8_t unk1F0[0x08];  // 1F0
	float height;  // 1F8
	std::uint32_t unk1FC;  // 1FC
	Sounds* sounds;  // 200
	std::uint8_t unk208[0x48];  // 208
	BSTArray<BGSRelationship*>* relationships;  // 250
	FaceData* faceData;  // 258
	BSTArray<Layer*>* tintLayers;  // 260
};

