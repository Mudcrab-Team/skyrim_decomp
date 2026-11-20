// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActiveEffect_vtbl; size 0xc8
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct ActiveEffect_vtbl {
    void (*AdjustForPerks)(char32_t* , char32_t* );
    void (*OnAdd)(char32_t* );
    void (*OnRemove)(void);
    char32_t*(*GetVisualsTarget)(void);
    void (*Update)(char32_t* , char32_t* , char32_t* );
    void (*EvaluateConditions)(float, bool);
    bool (*IsCausingHealthDamage)(void);
    void (*SetLocation)(char32_t* );
    void (*SaveGame)(char32_t* );
    void (*LoadGame)(char32_t* );
    void (*FinishLoadGame)(char32_t* );
    void (*Revert)(char32_t* );
    int (*Compare)(char32_t* );
    void (*HandleEvent)(char32_t* );
    void (*SwitchAttachedRoot)(char32_t* , char32_t* );
    void (*HandleQueuedStart)(void);
    bool (*ShouldDispelOnDeath)(void);
    bool (*GetAllowMultipleCastingSourceStacking)(void);
    void (*ClearTargetImpl)(void);
    void (*_dtor_ActiveEffect)(void);
    void (*Start)(void);
    void (*Finish)(void);
    bool (*CanFinish)(void);
    bool (*CheckCustomSkillUseConditions)(void);
    float (*GetCustomSkillUseMagnitudeMultiplier)(float);
};
static_assert(sizeof(ActiveEffect_vtbl) == 200, "ActiveEffect_vtbl layout differs from the PDB");
