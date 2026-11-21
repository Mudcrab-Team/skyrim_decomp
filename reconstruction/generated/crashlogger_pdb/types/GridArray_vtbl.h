// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GridArray_vtbl; size 0x48
#pragma once
struct GridArray_vtbl {
    void (*_dtor_GridArray)(void);
    void (*DetachAll)(void);
    void (*KillAll)(void);
    void (*SetCenter)(char32_t* );
    void (*Shift)(int, int);
    void (*Detach)(void);
    void (*ClearItem)(unsigned int, unsigned int);
    void (*MoveItem)(unsigned int, unsigned int, unsigned int, unsigned int);
    void (*SwapItem)(unsigned int, unsigned int, unsigned int, unsigned int);
};
static_assert(sizeof(GridArray_vtbl) == 72, "GridArray_vtbl layout differs from the PDB");
