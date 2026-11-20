// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESTopic: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetFormEditorID, IsParentForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// editorID: GUESS(low)
#pragma once

#include <cstdint>

class TESTopic
{
public:
    bool IsParentForm() const;
    const char* GetFormEditorID() const;

private:
    std::uint8_t padding00[0x58];
    const char* editorID;
};
