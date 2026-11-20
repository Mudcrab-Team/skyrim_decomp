// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FindTriangleForLocationFilter_vtbl; size 0x10
#pragma once
struct FindTriangleForLocationFilter_vtbl {
    void (*_dtor_FindTriangleForLocationFilter)(void);
    bool (*IsValidTri)(char32_t* , char32_t* , unsigned short, char32_t* );
};
static_assert(sizeof(FindTriangleForLocationFilter_vtbl) == 16, "FindTriangleForLocationFilter_vtbl layout differs from the PDB");
