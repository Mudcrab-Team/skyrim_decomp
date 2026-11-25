// Source exposure: mixed
// Code origin: Stamped as a twin of matched 0x692ea0 (skyrim_shared/actors/Character): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Licence: this file carries declarations derived from powerof3/CommonLibSSE and is GPL-3.0 (docs/authorizations.md).
// Source exposure: mixed. Drafted from local listings of the pinned image with
// the class layout and slot order from the generated skeleton; names are from CommonLibSSE-NG b93280e (MIT)
// and the powerof3 fork 654e55f (GPL-3.0, which this file therefore also carries) or the meh321 Address
// BGSLoadFormBuffer, BipedAnim, TESFaction, BSTSmartPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the type names only
// AIProcess::StartDeferredKill: GUESS(low); callee at 0x7285a0
// Function80ea60, Owner80ea60: GUESS(low) STANDIN
// biped2, unk270, unk279, unk27A, Owner80ea60, Owner80ea60::~Owner80ea60, Owner80ea60::SaveGame, Owner80ea60::LoadGame, Owner80ea60::InitLoadGame, Owner80ea60::FinishLoadGame, Owner80ea60::Revert, Owner80ea60::Predestroy, Owner80ea60::IsChild, Owner80ea60::GetFaceNodeSkinned, Owner80ea60::GetFaceGenAnimationData, Owner80ea60::GetBiped2, Owner80ea60::SetBiped, Owner80ea60::InitiateVampireFeedPackage, Owner80ea60::Unk_C4, Owner80ea60::Unk_C5, Owner80ea60::Unk_C6, Owner80ea60::OnArmorActorValueChanged, Owner80ea60::InitiateTresPassPackage, Owner80ea60::InitiateSpectator, Owner80ea60::CalcArmorRating, Owner80ea60::GetArmorBaseFactorSum, Owner80ea60::CalcUnarmedDamage, Owner80ea60::PrecacheData, Owner80ea60::Unk_128, Owner80ea60::Unk_129, unk100: GUESS(low) STANDIN
#pragma once
#include "Character.h"

// Other RTTI bases (not declared here; their vftable pointers lie inside the members): .?AVBSHandleRefObject@@, .?AVNiRefObject@@, .?AV?$BSTEventSink@UBSAnimationGraphEvent@@@@, .?AVIAnimationGraphManagerHolder@@, .?AVMagicTarget@@, .?AVActorValueOwner@@, .?AVActorState@@, .?AUIMovementState@@, .?AUIMovementInterface@@, .?AV?$BSTEventSink@VBSTransformDeltaEvent@@@@, .?AV?$BSTEventSink@VbhkCharacterMoveFinishEvent@@@@, .?AVIPostAnimationChannelUpdateFunctor@@
class Owner80ea60 : public ::Actor
{
public:
	// community declaration: virtual ~BaseFormComponent();
	~Owner80ea60() override;  // 00
	// community declaration: virtual void SaveGame(BGSSaveFormBuffer* a_buf);
	void SaveGame() override;  // 0E
	// community declaration: virtual void LoadGame(BGSLoadFormBuffer* a_buf);
	void LoadGame() override;  // 0F
	// community declaration: virtual void InitLoadGame(BGSLoadFormBuffer* a_buf);
	void InitLoadGame() override;  // 10
	// community declaration: virtual void FinishLoadGame(BGSLoadFormBuffer* a_buf);
	void FinishLoadGame() override;  // 11
	// community declaration: virtual void Revert(BGSLoadFormBuffer* a_buf);
	void Revert(BGSLoadFormBuffer* a_buf) override;  // 12
	// community declaration: virtual void Predestroy();
	void Predestroy() override;  // 3B
	// community declaration: virtual bool IsChild() const;
	void IsChild() override;  // 5E
	// community declaration: virtual BSFaceGenNiNode* GetFaceNodeSkinned();
	void GetFaceNodeSkinned() override;  // 61
	// community declaration: virtual BSFaceGenAnimationData* GetFaceGenAnimationData();
	void GetFaceGenAnimationData() override;  // 63
	// community declaration: virtual const BSTSmartPointer<BipedAnim>& GetBiped2() const;
	const BSTSmartPointer<BipedAnim>& GetBiped2() const override;  // 7F
	// community declaration: virtual void SetBiped(const BSTSmartPointer<BipedAnim>& a_biped);
	void SetBiped() override;  // 81
	// community declaration: virtual void InitiateVampireFeedPackage(Actor* a_target, TESObjectREFR* a_furniture);
	void InitiateVampireFeedPackage() override;  // C0
	// community declaration: virtual void Unk_C4(void);
	void Unk_C4(std::uint8_t a_arg1) override;  // C4
	// community declaration: virtual void Unk_C5(void);
	void Unk_C5() override;  // C5
	// community declaration: virtual void Unk_C6(void) = 0;
	void Unk_C6() override;  // C6
	// community declaration: virtual void OnArmorActorValueChanged();
	void OnArmorActorValueChanged() override;  // CA
	// community declaration: virtual bool InitiateTresPassPackage(TrespassPackage* a_trespassPackage);
	void InitiateTresPassPackage() override;  // D7
	// community declaration: virtual void InitiateSpectator(Actor* a_target);
	void InitiateSpectator() override;  // DC
	// community declaration: virtual float CalcArmorRating();
	void CalcArmorRating() override;  // E6
	// community declaration: virtual float GetArmorBaseFactorSum();
	void GetArmorBaseFactorSum() override;  // E7
	// community declaration: virtual float CalcUnarmedDamage();
	void CalcUnarmedDamage() override;  // E8
	// community declaration: virtual void PrecacheData();
	void PrecacheData() override;  // 120
	// community declaration: virtual void Unk_128(void);
	virtual void Unk_128();  // 128
	// community declaration: virtual void Unk_129(void);
	virtual std::uint8_t Unk_129();  // 129

	Owner80ea60();

	float Function80ea60() const;
	void StartDeferredKill();
	void SetCrimeFaction(TESFaction* a_faction);

	std::uint8_t unk100[0x168];  // 100
	BSTSmartPointer<BipedAnim> biped2;  // 268
	std::uint8_t unk270[9];  // 270
	std::uint8_t unk279;  // 279
	std::uint8_t unk27A;  // 27A
	std::uint8_t unk27B[0x3D];  // 27B
};
static_assert(sizeof(Owner80ea60) == 0x2B8, "size");
