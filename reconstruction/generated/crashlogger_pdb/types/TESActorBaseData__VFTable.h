// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESActorBaseData__VFTable; size 0x48
#pragma once

struct BaseFormComponent_9d659514;
struct TESActorBaseData_698bb182;
struct TESActorBaseData__VFTable {
    unsigned long long*(*dtor_0)(BaseFormComponent_9d659514* , char);
    int (*InitializeDataComponent_8)(void);
    int (*ClearDataComponent_10)(void);
    void (*CopyComponent_18)(void);
    void (*CopyFromTemplateForms_20)(void);
    char (*GetIsGhost_28)(TESActorBaseData_698bb182* );
    void (*GetInvulnerable_30)(TESActorBaseData_698bb182* );
    char (*Func7_38)(void);
    long long (*GetVoiceType_40)(TESActorBaseData_698bb182* );
};
static_assert(sizeof(TESActorBaseData__VFTable) == 72, "TESActorBaseData__VFTable layout differs from the PDB");
