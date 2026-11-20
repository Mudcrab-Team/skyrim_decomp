// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MagicTarget__VFTable; size 0x50
#pragma once
struct MagicTarget__VFTable {
    char (*Func1_8)(long long, long long, float);
    long long (*GetMagicTargetOwner_10)(void);
    void (*MagicTargetIsActor_18)(void);
    char (*IsInvulnerable_20)(void);
    void (*InvalidateCommandedActorEffect_28)(void);
    int (*CanAddActiveEffect_30)(void);
    void (*Func8_40)(void);
    void (*Func9_48)(void);
    void (*CheckResistance_50)(void);
    char (*CheckAbsorb_58)(void);
};
static_assert(sizeof(MagicTarget__VFTable) == 80, "MagicTarget__VFTable layout differs from the PDB");
