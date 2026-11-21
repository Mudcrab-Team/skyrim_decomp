// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSBatchRenderer_vtbl; size 0x20
#pragma once
struct BSBatchRenderer_vtbl {
    void (*_dtor_BSBatchRenderer)(void);
    void (*RegisterPassSorted)(char32_t* , unsigned int);
    void (*RegisterPass)(char32_t* , unsigned int);
    void (*RenderActivePassRange)(unsigned int, unsigned int, unsigned int);
};
static_assert(sizeof(BSBatchRenderer_vtbl) == 32, "BSBatchRenderer_vtbl layout differs from the PDB");
