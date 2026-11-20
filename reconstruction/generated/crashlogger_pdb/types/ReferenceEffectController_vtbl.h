// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ReferenceEffectController_vtbl; size 0x118
#pragma once
struct ReferenceEffectController_vtbl {
    void (*_dtor_ReferenceEffectController)(void);
    void (*HandleEvent)(char32_t* );
    float (*GetElapsedTime)(void);
    float (*GetScale)(void);
    void (*SwitchAttachedRoot)(char32_t* , char32_t* );
    char32_t*(*GetSourcePosition)(void);
    bool (*GetUseSourcePosition)(void);
    bool (*GetNoInitialFlare)(void);
    bool (*GetEffectPersists)(void);
    bool (*GetGoryVisuals)(void);
    void (*RemoveHitEffect)(char32_t* );
    char32_t*(*GetTargetReference)(void);
    char32_t*(*GetHitEffectArt)(void);
    char32_t*(*GetHitEffectShader)(void);
    bool (*GetManagerHandlesSaveLoad)(void);
    char32_t*(*GetAttachRoot)(void);
    float (*GetParticleAttachExtent)(void);
    bool (*GetUseParticleAttachExtent)(void);
    bool (*GetDoParticles)(void);
    bool (*GetParticlesUseLocalSpace)(void);
    bool (*GetUseRootWorldRotate)(void);
    bool (*GetIsRootActor)(void);
    bool (*GetClearWhenCellIsUnloaded)(void);
    bool (*EffectShouldFaceTarget)(void);
    char32_t*(*GetFacingTarget)(void);
    bool (*GetShaderUseParentCell)(void);
    bool (*EffectAttachesToCamera)(void);
    bool (*EffectRotatesWithCamera)(void);
    bool (*GetAllowTargetRoot)(void);
    bool (*IsReadyForAttach)(void);
    void (*SetWindPoint)(char32_t* );
    char32_t*(*GetWindPoint)(void);
    bool (*GetAllowNo3D)(void);
    void (*SaveGame)(char32_t* );
    void (*LoadGame)(char32_t* );
};
static_assert(sizeof(ReferenceEffectController_vtbl) == 280, "ReferenceEffectController_vtbl layout differs from the PDB");
