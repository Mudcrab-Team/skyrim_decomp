// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPathing_vtbl; size 0x48
#pragma once
struct BSPathing_vtbl {
    void (*_dtor_BSPathing)(void);
    void (*GetPotentialNavMeshInfoForLocation)(char32_t* );
    bool (*GetAllLoadedNavmeshes1)(char32_t* , char32_t* );
    bool (*GetAllLoadedNavmeshes2)(char32_t* );
    bool (*GetAllLoadedNavmeshes3)(char32_t* );
    bool (*GetAllLoadedNavmeshes4)(char32_t* );
    bool (*GetAllLoadedNavmeshes5)(char32_t* );
    void (*GetSelectedDebugRef)(void);
    bool (*GetPathingDoorFromCollision)(char32_t* , char32_t* );
};
static_assert(sizeof(BSPathing_vtbl) == 72, "BSPathing_vtbl layout differs from the PDB");
