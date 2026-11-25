// Source exposure: mixed (community declarations, sibling shape and the pinned image listing).
// Code origin: adapted from the cited sibling body; layout checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESReactionForm.cpp:21
// BaseFormComponent, TESReactionForm, TESReactionForm::~TESReactionForm, groupFormType, reactions: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FreeReactionList: SIBLING(fo4-private@1b765c70, author-permission)
// ReactionList, head, tail: GUESS(low); the member type whose destructor is an out-of-line call
#pragma once

#include <cstdint>

struct ReactionList
{
    ~ReactionList();

    void* head;  // 00
    void* tail;  // 08
};

class BaseFormComponent
{
public:
    virtual ~BaseFormComponent() {}  // 00
    virtual void InitializeDataComponent() = 0;  // 01
    virtual void ClearDataComponent() = 0;  // 02
    virtual void CopyComponent(BaseFormComponent* a_rhs);  // 03
};
static_assert(sizeof(BaseFormComponent) == 0x8, "BaseFormComponent size");

class TESReactionForm : public BaseFormComponent
{
public:
    ~TESReactionForm() override;  // 00, compared: 0x1ef970
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02

    void FreeReactionList();

    ReactionList reactions;  // 08
    std::uint8_t groupFormType;  // 18
    std::uint8_t pad19[7];  // 19
};
static_assert(sizeof(TESReactionForm) == 0x20, "TESReactionForm size");
