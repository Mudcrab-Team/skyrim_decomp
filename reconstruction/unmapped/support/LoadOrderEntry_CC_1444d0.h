// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// LoadOrderEntry_CC, LoadOrderEntry: EXE_RTTI
// LoadOrderEntry: STANDIN EXE_RTTI; only its out-of-line destructor is declared
// LoadOrderEntry::~LoadOrderEntry: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

class LoadOrderEntry
{
public:
    LoadOrderEntry();
    virtual ~LoadOrderEntry();
};

class LoadOrderEntry_CC : public LoadOrderEntry
{
public:
    LoadOrderEntry_CC();
    ~LoadOrderEntry_CC() override {}

    char unk08[0xD8];
};
static_assert(sizeof(LoadOrderEntry_CC) == 0xE0, "LoadOrderEntry_CC size from the deleting destructor");
