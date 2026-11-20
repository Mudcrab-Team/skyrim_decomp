// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ReferenceEffectController__VFTable; size 0x118
#pragma once

struct ReferenceEffectController_aa59977e;
struct ReferenceEffectController__VFTable {
    long long (*dtor_0)(ReferenceEffectController_aa59977e* , char);
    void (*Func1_8)(void);
    void (*Func2_10)(void);
    void (*Func3_18)(void);
    void (*Func4_20)(void);
    float*(*GetSourcePosition_28)(void);
    char (*GetUseSourcePosition_30)(void);
    char (*GetNoInitialFlare_38)(void);
    char (*GetEffectPersists_40)(void);
    char (*GetGoryVisuals_48)(void);
    void (*RemoveHitEffect_50)(void);
    int (*GetTargetReference_58)(void);
    int (*GetHitEffectArt_60)(void);
    int (*GetHitEffectShader_68)(void);
    int (*GetManagerHandlesSaveLoad_70)(void);
    int (*GetAttachRoot_78)(ReferenceEffectController_aa59977e* );
    void (*GetParticleAttachExtent_80)(void);
    char (*GetUseParticleAttachExtent_88)(void);
    char (*GetDoParticles_90)(void);
    char (*GetParticlesUseLocalSpace_98)(void);
    char (*GetUseRootWorldRotate_A0)(void);
    char (*GetIsRootActor_A8)(ReferenceEffectController_aa59977e* );
    char (*GetClearWhenCellIsUnloaded_B0)(void);
    char (*EffectShouldFaceTarget_B8)(void);
    long long (*GetFacingTarget_C0)(void);
    char (*GetShaderUseParentCell_C8)(void);
    char (*EffectAttachesToCamera_D0)(void);
    char (*EffectRotatesWithCamera_D8)(void);
    char (*GetAllowTargetRoot_E0)(void);
    char (*IsReadyForAttach_E8)(void);
    void (*SetWindPoint_F0)(void);
    float*(*GetWindPoint_F8)(void);
    char (*GetAllowNo3D_100)(void);
    void (*SaveGame_108)(void);
    void (*LoadGame_110)(void);
};
static_assert(sizeof(ReferenceEffectController__VFTable) == 280, "ReferenceEffectController__VFTable layout differs from the PDB");
