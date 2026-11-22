// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original; names and declarations from CharmedBaryon/CommonLibSSE-NG (MIT)
// TESReactionForm: EXE_RTTI; class name and base from the image RTTI
#pragma once

#include <cstdint>

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

	// reactions: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
	struct GROUP_REACTION
	{
		void* form;                   // 00
		std::int32_t reaction;        // 08
		std::uint32_t fightReaction;  // 0C
	};
	static_assert(sizeof(GROUP_REACTION) == 0x10, "layout");

	template <class T>
	struct BSSimpleList
	{
		T item;                 // 00
		BSSimpleList<T>* next;  // 08
	};
	static_assert(sizeof(BSSimpleList<GROUP_REACTION*>) == 0x10, "layout");

	std::uint32_t Function1f0370(const void* a_faction) const;

	BSSimpleList<GROUP_REACTION*> reactions;  // 08
	// groupFormType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares stl::enumeration<FormType, std::uint8_t>, a plain byte here
	std::uint8_t groupFormType;  // 18
	// unk19: GUESS(low); padding and unrecovered tail
	std::uint8_t unk19[7];  // 19
};
static_assert(sizeof(TESReactionForm) == 0x20, "layout");
