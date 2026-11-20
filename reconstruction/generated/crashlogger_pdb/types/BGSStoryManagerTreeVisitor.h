// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSStoryManagerTreeVisitor; size 0x40
#pragma once

#include "BSTArray_RE__BGSStoryManagerTreeForm_9796e549.h"
struct BGSStoryManagerQuestNode_b5a3032e;
struct BGSStoryManagerTreeVisitor_vtbl;
struct PeriodicUpdateTimer;
struct BGSStoryManagerTreeVisitor {
    BGSStoryManagerTreeVisitor_vtbl* __vftable;
    PeriodicUpdateTimer* timer;
    int currentCursorDepth;
    unsigned int pad14;
    BGSStoryManagerQuestNode_b5a3032e* lastQuestParent;
    BSTArray_RE__BGSStoryManagerTreeForm_9796e549 cursorAncestry;
    unsigned int queryID;
    unsigned int pad3C;
};
static_assert(sizeof(BGSStoryManagerTreeVisitor) == 64, "BGSStoryManagerTreeVisitor layout differs from the PDB");
