// Source exposure: mixed (community headers; compared functions from the pinned image; fo4-private body).
// Origin: adapted from the cited sibling body; the Skyrim class views are partial stand-ins.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSLoadGameBuffer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); partial view
// TESForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); partial view
// MagicItem: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); partial view
// LoadFormID: SIBLING(fo4-private@1b765c70, author-permission)
// GetFormByNumericID: SIBLING(fo4-private@1b765c70, author-permission); the Skyrim lookup is TESForm::LookupByID
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/Buffers/BGSSaveLoadFormID.inl:6
#pragma once

#include <cstdint>

class TESForm
{
public:
    virtual ~TESForm();
    static TESForm* GetFormByNumericID(std::uint32_t aFormID);
};

class MagicItem : public TESForm
{
};

class BGSLoadGameBuffer
{
public:
    virtual ~BGSLoadGameBuffer();
    virtual std::uint8_t GetVersion();

    bool LoadFormID(std::uint32_t& aFormID);

    template <class T>
    bool LoadFormID(T*& arpForm);
};

template <class T>
inline bool BGSLoadGameBuffer::LoadFormID(T*& arpForm)
{
    std::uint32_t uiFormID = 0;
    bool bResult = LoadFormID(uiFormID);
    arpForm = dynamic_cast<T*>(TESForm::GetFormByNumericID(uiFormID));
    return bResult;
}
