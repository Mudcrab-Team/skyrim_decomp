// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActiveEffect_vtbl; size 0xc8
// one of 2 different PDB types sharing this name
#pragma once

struct ActiveEffect;
struct Actor_b2630b95;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSFixedString_char_83b572b4;
struct MagicTarget;
struct NiNode;
struct NiPoint3;
struct TESObjectREFR_b225f218;
struct ActiveEffect_vtbl_d36453dd {
    void (*AdjustForPerks)(Actor_b2630b95* , MagicTarget* );
    void (*OnAdd)(MagicTarget* );
    void (*OnRemove)(void);
    TESObjectREFR_b225f218*(*GetVisualsTarget)(void);
    void (*Update)(float);
    void (*EvaluateConditions)(float, bool);
    bool (*IsCausingHealthDamage)(void);
    void (*SetLocation)(NiPoint3* );
    void (*SaveGame)(BGSSaveFormBuffer* );
    void (*LoadGame)(BGSLoadFormBuffer* );
    void (*FinishLoadGame)(BGSLoadFormBuffer* );
    void (*Revert)(BGSLoadFormBuffer* );
    int (*Compare)(ActiveEffect* );
    void (*HandleEvent)(BSFixedString_char_83b572b4* );
    void (*SwitchAttachedRoot)(NiNode* , NiNode* );
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
static_assert(sizeof(ActiveEffect_vtbl_d36453dd) == 200, "ActiveEffect_vtbl_d36453dd layout differs from the PDB");
