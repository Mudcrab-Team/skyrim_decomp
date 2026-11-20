// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSArtObjectCloneTask; size 0x90
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct BGSArtObjectCloneTask__VFTable;
struct BSResource__IEntryDB__PostFlushNotify__VFTable;
struct BSTask__VFTable;
struct BGSArtObjectCloneTask {
    BGSArtObjectCloneTask__VFTable* vftable_BGSArtObjectCloneTask_0;
    BSTask__VFTable* vftable_BSTask_8;
    char _pad_10[40];
    BSResource__IEntryDB__PostFlushNotify__VFTable* vftable_PostFlushNotify_38;
    char _pad_40[80];
};
static_assert(sizeof(BGSArtObjectCloneTask) == 144, "BGSArtObjectCloneTask layout differs from the PDB");
