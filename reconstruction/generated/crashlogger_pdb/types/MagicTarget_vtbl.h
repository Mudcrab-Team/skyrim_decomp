// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MagicTarget_vtbl; size 0x60
#pragma once
struct MagicTarget_vtbl {
    void (*_dtor_MagicTarget)(void);
    bool (*AddTarget)(char32_t* );
    char32_t*(*GetTargetStatsObject)(void);
    bool (*MagicTargetIsActor)(void);
    bool (*IsInvulnerable)(void);
    void (*InvalidateCommandedActorEffect)(char32_t* );
    bool (*CanAddActiveEffect)(void);
    char32_t*(*GetActiveEffectList)(void);
    void (*EffectAdded)(char32_t* );
    void (*EffectRemoved)(char32_t* );
    float (*CheckResistance)(char32_t* , char32_t* , char32_t* );
    bool (*CheckAbsorb)(char32_t* , char32_t* , char32_t* );
};
static_assert(sizeof(MagicTarget_vtbl) == 96, "MagicTarget_vtbl layout differs from the PDB");
