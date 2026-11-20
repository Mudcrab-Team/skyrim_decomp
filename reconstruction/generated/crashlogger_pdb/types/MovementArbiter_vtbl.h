// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MovementArbiter_vtbl; size 0x90
#pragma once
struct MovementArbiter_vtbl {
    void (*_dtor_MovementArbiter)(void);
    char32_t*(*GetPipelineStage)(void);
    char32_t*(*GetArbiterType)(void);
    unsigned char (*GetArbiterSaveType)(void);
    void (*RegisterWithController)(char32_t* );
    char32_t*(*GetDebugRenderingInterface)(void);
    void (*Activate)(char32_t* );
    void (*Init)(char32_t* );
    void (*UpdateSmallDelta)(char32_t* );
    void (*UpdateLargeDelta)(char32_t* );
    void (*Kill)(void);
    void (*Deactivate)(char32_t* );
    void (*UnregisterWithController)(void);
    void (*SaveGame)(char32_t* );
    void (*LoadGame)(char32_t* );
    bool (*AddAgent)(char32_t* );
    bool (*RemoveAgent)(char32_t* );
    void (*RemoveAllAgents)(void);
};
static_assert(sizeof(MovementArbiter_vtbl) == 144, "MovementArbiter_vtbl layout differs from the PDB");
