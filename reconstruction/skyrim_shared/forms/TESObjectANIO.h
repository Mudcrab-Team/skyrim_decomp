// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectANIO: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESObjectANIO::GetFormEditorID, TESObjectANIO::InitItemImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>
#include "TESForm.h"

// g_defaultFormEditorIDString: GUESS(low); the default string address in .rdata used by GetFormEditorID
extern const char g_defaultFormEditorIDString[];

class TESObjectANIO : public TESForm
{
public:
    virtual const char* GetFormEditorID() const;  // compared: 0x27bb70

    // unknown20: GUESS(low); the helper of InitItemImpl receives this + 0x20
    std::uint8_t unknown20[0x38];  // 20
    // editorID: GUESS(low)
    // editorID is read by GetFormEditorID; a null value falls back to a default string
    const char* editorID;  // 58
};
