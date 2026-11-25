// Source exposure: mixed (community declarations, sibling shape and the pinned image listing).
// Code origin: adapted from the cited sibling body; layout checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESLeveledList.cpp:118
// BaseFormComponent, TESLeveledList, TESLeveledList::~TESLeveledList: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FreeLeveledList: GUESS(medium); the name the sibling's destructor calls
// unknown08: GUESS(low)
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

class TESLeveledList : public BaseFormComponent
{
public:
    ~TESLeveledList() override;  // 00, compared: 0x1e8810
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02

    void FreeLeveledList();

    std::uint8_t unknown08[0x20];  // 08
};
