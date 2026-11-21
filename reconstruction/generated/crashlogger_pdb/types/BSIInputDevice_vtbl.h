// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSIInputDevice_vtbl; size 0x48
#pragma once
struct BSIInputDevice_vtbl {
    void (*_dtor_BSIInputDevice)(void);
    void (*Initialize)(void);
    void (*Poll)(float);
    void (*Shutdown)(void);
    bool (*GetButtonNameFromID)(int, char32_t* );
    unsigned int (*GetMappingKey)(char32_t* );
    bool (*GetKeyCodeFromID)(int, unsigned int* );
    bool (*IsEnabled)(void);
    void (*ClearInputState)(void);
};
static_assert(sizeof(BSIInputDevice_vtbl) == 72, "BSIInputDevice_vtbl layout differs from the PDB");
