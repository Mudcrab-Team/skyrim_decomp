// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// TESIcon: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BaseFormComponent, TESTexture: STANDIN EXE_RTTI
// TESIcon::GetDefaultPath, TESIcon::~TESIcon: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BaseFormComponent::~BaseFormComponent, unknown08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BaseFormComponent
{
public:
    virtual ~BaseFormComponent() = default;
};
static_assert(sizeof(BaseFormComponent) == 0x8, "BaseFormComponent size");

class TESTexture : public BaseFormComponent
{
public:
    std::uint8_t unknown08[0x8];  // 08
};
static_assert(sizeof(TESTexture) == 0x10, "TESTexture size");

class TESIcon : public TESTexture
{
public:
    TESIcon();
    virtual const char* GetDefaultPath() const;  // compared: 0x1e85e0
    virtual ~TESIcon();  // compared: 0x1e85f0 (scalar deleting destructor)
};
static_assert(sizeof(TESIcon) == 0x10, "TESIcon size");
