// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// TESReactionForm: EXE_RTTI; class name and base from the image RTTI
#pragma once

#include <cstdint>

// TESForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); opaque here, only a pointer is compared
class TESForm;

// GROUP_REACTION, GROUP_REACTION::form, ::reaction, ::fightReaction: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct GROUP_REACTION
{
	TESForm*      form;           // 00
	std::int32_t  reaction;       // 08
	std::int32_t  fightReaction;  // 0C, FIGHT_REACTION in NG, a plain integer here
};
static_assert(sizeof(GROUP_REACTION) == 0x10, "layout");

// BSSimpleList, ::item, ::next: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); inline first node, layout from the listings
struct GroupReactionList
{
	GROUP_REACTION*    item;  // 00
	GroupReactionList* next;  // 08
};

// BaseFormComponent: STANDIN EXE_RTTI; class name and base from the image RTTI, 4 primary vftable slots
// sizeof BaseFormComponent 0x8: OBSERVED; size argument of operator delete in the deleting destructor (slot 0)
class BaseFormComponent
{
public:
	// BaseFormComponent::~BaseFormComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 0
	virtual ~BaseFormComponent();  // 00
	// BaseFormComponent::InitializeDataComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 1
	virtual void InitializeDataComponent();  // 01
	// BaseFormComponent::ClearDataComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 2
	virtual void ClearDataComponent();  // 02
	// BaseFormComponent::CopyComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 3
	virtual void CopyComponent();  // 03
};
static_assert(sizeof(BaseFormComponent) == 0x8, "layout");

// TESReactionForm: EXE_RTTI; class name and base from the image RTTI, 4 primary vftable slots
// sizeof TESReactionForm 0x20: OBSERVED; size argument of operator delete in the deleting destructor (slot 0)
class TESReactionForm : public BaseFormComponent
{
public:
	// TESReactionForm::~TESReactionForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 0
	~TESReactionForm() override;  // 00
	// TESReactionForm::InitializeDataComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 1
	void InitializeDataComponent() override;  // 01
	// TESReactionForm::ClearDataComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 2
	void ClearDataComponent() override;  // 02
	// TESReactionForm::CopyComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 3
	void CopyComponent() override;  // 03

	// reactions: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares BSSimpleList, the members are not recovered
	// GetReaction, GetFactionCombatRelation: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
	std::int32_t GetReaction(TESForm* a_form);
	std::int32_t GetFactionCombatRelation(TESForm* a_form);

	GroupReactionList reactions;  // 08
	// groupFormType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares stl::enumeration<FormType, std::uint8_t>, a plain byte here
	std::uint8_t groupFormType;  // 18
	// unk19: GUESS(low); padding and unrecovered tail
	std::uint8_t unk19[7];  // 19
};
static_assert(sizeof(TESReactionForm) == 0x20, "layout");
