// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MagicItemData: EXE_RTTI
// BSString: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN; only the destructor the function needs
// MagicItemData::unk08: GUESS(low); same destructor as TESGlobal::formEditorID
#pragma once

class BSString
{
public:
    ~BSString();

    char* data;
    unsigned short maxLength;
    unsigned short length;
    unsigned int pad0C;
};

class MagicItemData
{
public:
    MagicItemData();
    virtual ~MagicItemData() {}

    BSString unk08;
    char unk18[0x8];
};
static_assert(sizeof(MagicItemData) == 0x20, "MagicItemData size from the deleting destructor");
