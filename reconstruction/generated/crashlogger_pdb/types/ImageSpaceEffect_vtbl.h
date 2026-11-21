// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ImageSpaceEffect_vtbl; size 0x50
#pragma once
struct ImageSpaceEffect_vtbl {
    void (*_dtor_ImageSpaceEffect)(void);
    void (*Render)(char32_t* , char32_t* );
    void (*Setup)(char32_t* , char32_t* );
    void (*ShutDown)(void);
    void (*BorrowTextures)(char32_t* );
    void (*ReturnTextures)(void);
    bool (*IsActive)(void);
    bool (*UpdateParams)(char32_t* );
    bool (*SetRenderStates)(char32_t* );
    bool (*RestoreRenderStates)(char32_t* );
};
static_assert(sizeof(ImageSpaceEffect_vtbl) == 80, "ImageSpaceEffect_vtbl layout differs from the PDB");
