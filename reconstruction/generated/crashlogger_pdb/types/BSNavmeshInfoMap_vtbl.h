// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSNavmeshInfoMap_vtbl; size 0x30
#pragma once
struct BSNavmeshInfoMap_vtbl {
    void (*_dtor_BSNavmeshInfoMap)(void);
    char32_t*(*GetNavMeshInfoFixID)(unsigned int);
    char32_t*(*GetNavmeshInfo)(unsigned int);
    void (*GetAllNavMeshInfo)(char32_t* );
    void (*BuildListOfConnectedInfos)(char32_t* , char32_t* );
    void (*ForEach)(char32_t* );
};
static_assert(sizeof(BSNavmeshInfoMap_vtbl) == 48, "BSNavmeshInfoMap_vtbl layout differs from the PDB");
