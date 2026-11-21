// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPathingCellManager_vtbl; size 0x58
#pragma once
struct BSPathingCellManager_vtbl {
    float (*GetExteriorCellWidth)(void);
    bool (*GetPathingCell)(char32_t* , char32_t* , char32_t* );
    bool (*IsCloseTo)(char32_t* , char32_t* , char32_t* , char32_t* , float);
    void (*FindPotentialNavmeshesForLocation1)(char32_t* , float, char32_t* );
    void (*FindPotentialNavmeshesForLocation2)(char32_t* , float, char32_t* );
    void (*FindConnectedNavmeshesForLocation3)(char32_t* , float, char32_t* );
    void (*FindConnectedNavmeshesForLocation4)(char32_t* , float, char32_t* );
    void (*FindConnectedNavmeshesForLocation5)(char32_t* , float, char32_t* );
    void (*FindConnectedNavmeshesForLocation6)(char32_t* , float, char32_t* );
    float (*GetWaterHeight)(char32_t* );
    void (*_dtor_BSPathingCellManager)(void);
};
static_assert(sizeof(BSPathingCellManager_vtbl) == 88, "BSPathingCellManager_vtbl layout differs from the PDB");
