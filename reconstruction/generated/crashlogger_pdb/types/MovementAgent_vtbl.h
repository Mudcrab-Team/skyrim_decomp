// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MovementAgent_vtbl; size 0x70
#pragma once
struct MovementAgent_vtbl {
    void (*_dtor_MovementAgent)(void);
    char32_t*(*GetAgentType)(void);
    unsigned char (*GetAgentSaveType)(void);
    char32_t*(*GetPipelineStageInterface)(char32_t* );
    void (*RegisterWithController)(char32_t* );
    char32_t*(*GetDebugRenderingInterface)(void);
    void (*Activate)(char32_t* );
    void (*Init)(char32_t* );
    void (*Kill)(void);
    void (*Deactivate)(char32_t* );
    void (*UnregisterWithController)(void);
    void (*SaveGame)(char32_t* );
    void (*LoadGame)(char32_t* );
    void (*FinishLoadGame)(char32_t* );
};
static_assert(sizeof(MovementAgent_vtbl) == 112, "MovementAgent_vtbl layout differs from the PDB");
