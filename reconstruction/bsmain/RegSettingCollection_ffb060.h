// Source exposure: mixed.
// Code origin: original; pinned-image observations and labelled naming sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RegSettingCollection: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RegSettingCollection::CloseHandle: CRASHLOGGER_PDB(59818@2026.10.24)
// subKey, handle: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// vtable: GUESS(low)
#pragma once
#include <cstdint>

class RegSettingCollection
{
public:
    bool CloseHandle();
    void* vtable;
    char subKey[0x104];
    void* handle;
};
