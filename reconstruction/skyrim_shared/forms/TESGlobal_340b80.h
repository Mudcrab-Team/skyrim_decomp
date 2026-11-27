// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESGlobal, TESGlobal::formEditorID, TESGlobal::type: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI STANDIN; only the destructor the function needs
// BSString: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN; only the destructor the function needs
// TESForm::ClearData: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); the sibling TESGlobal destructor calls it
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

class TESForm
{
public:
    TESForm();
    virtual ~TESForm();
    virtual void ClearData();

    char unk08[0x18];
};

class TESGlobal : public TESForm
{
public:
    TESGlobal();
    ~TESGlobal() override
    {
        TESForm::ClearData();
    }

    BSString formEditorID;
    unsigned char type;
    char pad31[0x7];
};
static_assert(sizeof(TESGlobal) == 0x38, "TESGlobal size from the deleting destructor");
