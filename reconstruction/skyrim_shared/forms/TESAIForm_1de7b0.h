// Source exposure: mixed (community declarations, sibling shape and the pinned image listing).
// Code origin: adapted from the cited sibling body; layout checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESAIForm.cpp:27
// BaseFormComponent, TESAIForm, TESAIForm::~TESAIForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FreePackageList: SIBLING(fo4-private@1b765c70, author-permission)
// AIPackList: GUESS(medium); the name the sibling's destructor uses for this member
// PackageList, unknown08, head, tail: GUESS(low)
#pragma once

#include <cstdint>

struct PackageList
{
    ~PackageList();
    void FreePackageList();

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

class TESAIForm : public BaseFormComponent
{
public:
    ~TESAIForm() override;  // 00, compared: 0x1de7b0
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02

    std::uint8_t unknown08[0x10];  // 08
    PackageList AIPackList;  // 18
};
static_assert(sizeof(TESAIForm) == 0x28, "TESAIForm size");
