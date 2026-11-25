// Source exposure: mixed (community declarations, sibling shape and the pinned image listing).
// Code origin: adapted from the cited sibling body; layout checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESSpellList.cpp:10
// BaseFormComponent, TESSpellList, TESSpellList::~TESSpellList: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESSpellList::FreeSpellList: SIBLING(fo4-private@1b765c70, author-permission)
// actorEffects: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

class BaseFormComponent
{
public:
    virtual ~BaseFormComponent() {}  // 00
    virtual void InitializeDataComponent() = 0;  // 01
    virtual void ClearDataComponent() = 0;  // 02
    virtual void CopyComponent(BaseFormComponent* a_rhs);  // 03
};
static_assert(sizeof(BaseFormComponent) == 0x8, "BaseFormComponent size");

class TESSpellList : public BaseFormComponent
{
public:
    ~TESSpellList() override;  // 00, compared: 0x1f0a90
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02

    void FreeSpellList();

    void* actorEffects;  // 08
};
