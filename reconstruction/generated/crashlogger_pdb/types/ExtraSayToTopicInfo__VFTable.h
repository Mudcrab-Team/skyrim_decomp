// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraSayToTopicInfo__VFTable; size 0x18
#pragma once

struct BSExtraData;
struct ExtraSayToTopicInfo__VFTable {
    unsigned long long*(*dtor_0)(BSExtraData* , char);
    int (*GetExtraDataId_8)(void);
    char (*IsEqual_10)(void);
};
static_assert(sizeof(ExtraSayToTopicInfo__VFTable) == 24, "ExtraSayToTopicInfo__VFTable layout differs from the PDB");
