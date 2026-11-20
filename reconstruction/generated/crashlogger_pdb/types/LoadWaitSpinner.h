// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LoadWaitSpinner; size 0x68
#pragma once

#include "BSTEventSink_RE__BGSSaveLoadManagerEvent_dc6c2090.h"
#include "BSTEventSink_RE__BSGamerProfileEvent_9d3066b0.h"
#include "BSTEventSink_RE__BSSystemEvent_a1441324.h"
#include "GFxValue.h"
#include "IMenu_09c1ffe2.h"
struct LoadWaitSpinner {
    IMenu_09c1ffe2 _base;
    BSTEventSink_RE__BSSystemEvent_a1441324 _base_BSTEventSink_RE_BSSystemEvent_;
    BSTEventSink_RE__BSGamerProfileEvent_9d3066b0 _base_BSTEventSink_RE_BSGamerProfileEvent_;
    BSTEventSink_RE__BGSSaveLoadManagerEvent_dc6c2090 _base_BSTEventSink_RE_BGSSaveLoadManagerEvent_;
    GFxValue root;
    int unk60;
    bool fadeIn;
    unsigned char pad65;
    unsigned short pad66;
};
static_assert(sizeof(LoadWaitSpinner) == 104, "LoadWaitSpinner layout differs from the PDB");
