// Code origin: original; the listing and community declarations only
// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BaseFormComponent: STANDIN EXE_RTTI COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only class names, base chain,
// slot order and sizes are claimed.
#pragma once

#include <cstddef>
#include <cstdint>

// BaseFormComponent: STANDIN EXE_RTTI; class name and base from the image RTTI, 4 primary vftable slots
// sizeof BaseFormComponent 0x8: OBSERVED; size argument of operator delete in the deleting destructor (slot 0)
class BaseFormComponent
{
public:
	// BaseFormComponent::~BaseFormComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 0, target 0x146610
	virtual ~BaseFormComponent() {}  // 00
	// BaseFormComponent::InitializeDataComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 1, target 0x15a97c8
	virtual void InitializeDataComponent();  // 01
	// BaseFormComponent::ClearDataComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 2, target 0x15a97c8
	virtual void ClearDataComponent();  // 02
	// BaseFormComponent::CopyComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 3, target 0x145470
	virtual void CopyComponent();  // 03
};
static_assert(sizeof(BaseFormComponent) == 0x8, "layout");

// BGSImpactDataSet, BGSMaterialType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); opaque, only used by pointer
class BGSImpactDataSet;
class BGSMaterialType;

// BGSBlockBashData: EXE_RTTI; class name and base from the image RTTI, 4 primary vftable slots
// sizeof BGSBlockBashData 0x18: OBSERVED; size argument of operator delete in the deleting destructor (slot 0)
class BGSBlockBashData : public ::BaseFormComponent
{
public:
	// BGSBlockBashData::BGSBlockBashData: GUESS(low); declared so that the vftable and the deleting destructor are emitted in this unit
	BGSBlockBashData();
	// BGSBlockBashData::~BGSBlockBashData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 0, target 0x1d23c0, inherited name
	~BGSBlockBashData() override {}  // 00
	// BGSBlockBashData::InitializeDataComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 1, target 0x1d2240, inherited name
	void InitializeDataComponent() override;  // 01
	// BGSBlockBashData::ClearDataComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 2, target 0x1d2260, inherited name
	void ClearDataComponent() override;  // 02
	// BGSBlockBashData::CopyComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 3, target 0x1d2340, inherited name
	void CopyComponent() override;  // 03

	// blockBashImpactDataSet: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
	BGSImpactDataSet* blockBashImpactDataSet;  // 08
	// altBlockMaterialType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
	BGSMaterialType* altBlockMaterialType;  // 10
};
static_assert(sizeof(BGSBlockBashData) == 0x18, "layout");

// TESForm, TESObjectARMO, TESObjectWEAP: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only formType and the
// BGSBlockBashData base offset are declared, as members
class TESForm
{
public:
	enum FormType : std::uint8_t
	{
		kArmor = 0x1A,
		kWeapon = 0x29
	};

	void*         vtable;      // 00
	std::uint8_t  unk08[0x12]; // 08
	std::uint8_t  formType;    // 1A
	std::uint8_t  pad1B;       // 1B
	std::uint32_t pad1C;       // 1C
};
static_assert(sizeof(TESForm) == 0x20, "layout");

class TESObjectARMO : public TESForm
{
public:
	std::uint8_t     unk20[0x1C0 - 0x20];  // 20
	BGSBlockBashData blockBashData;        // 1C0
};

class TESObjectWEAP : public TESForm
{
public:
	std::uint8_t     unk20[0x128 - 0x20];  // 20
	BGSBlockBashData blockBashData;        // 128
};

// GetBlockBashData: GUESS(low); returns the block-bash component of an armor or weapon form
BGSBlockBashData* GetBlockBashData(TESForm* a_form);
