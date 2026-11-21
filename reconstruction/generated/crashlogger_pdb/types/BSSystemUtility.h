// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSSystemUtility; size 0x128
#pragma once

#include "BSTEventSink_RE__BSGamepadEvent_08fd84d3.h"
#include "BSTEventSource_RE__BSSystemEvent_5901f1da.h"
struct BSSystemUtility {
    BSTEventSink_RE__BSGamepadEvent_08fd84d3 _base;
    BSTEventSource_RE__BSSystemEvent_5901f1da _base_BSTEventSource_RE_BSSystemEvent_;
    unsigned long long unk060[24];
    unsigned char unk120;
    unsigned char unk121;
    unsigned short pad122;
    unsigned int pad124;
};
static_assert(sizeof(BSSystemUtility) == 296, "BSSystemUtility layout differs from the PDB");
