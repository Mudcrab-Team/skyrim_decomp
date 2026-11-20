// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Journal_QuestsTab; size 0x38
#pragma once

#include "GFxValue.h"
#include "JournalTab.h"
struct Journal_QuestsTab {
    JournalTab _base;
    GFxValue titleList;
    bool unk30;
    unsigned char unk31;
    unsigned short unk32;
    unsigned int unk34;
};
static_assert(sizeof(Journal_QuestsTab) == 56, "Journal_QuestsTab layout differs from the PDB");
