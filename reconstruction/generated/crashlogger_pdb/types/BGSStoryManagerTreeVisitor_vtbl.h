// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSStoryManagerTreeVisitor_vtbl; size 0x28
#pragma once

#include "VisitControl.h"
struct BGSStoryManagerTreeVisitor_vtbl {
    void (*_dtor_BGSStoryManagerTreeVisitor)(void);
    VisitControl (*VisitBranchNode)(char32_t* );
    VisitControl (*VisitQuestNode)(char32_t* , bool);
    VisitControl (*VisitQuest)(char32_t* );
    void (*Revert)(char32_t* );
};
static_assert(sizeof(BGSStoryManagerTreeVisitor_vtbl) == 40, "BGSStoryManagerTreeVisitor_vtbl layout differs from the PDB");
