// Source exposure: mixed (community headers; the pinned image listing).
// BaseFormComponent, TESFullName, BSFixedString, fullName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
// BSFixedString::value: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once

class BaseFormComponent
{
public:
    virtual ~BaseFormComponent() {}
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    virtual void CopyComponent(BaseFormComponent* a_rhs);
};

class BSFixedString
{
public:
    ~BSFixedString();

    const char* value;  // 00
};

class TESFullName : public BaseFormComponent
{
public:
    ~TESFullName() override;

    BSFixedString fullName;  // 08
};
static_assert(sizeof(TESFullName) == 0x10, "TESFullName size");
