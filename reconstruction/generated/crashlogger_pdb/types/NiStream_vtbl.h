// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiStream_vtbl; size 0xc0
#pragma once
struct NiStream_vtbl {
    void (*_dtor_NiStream)(void);
    bool (*Load1)(char32_t* );
    bool (*Load2)(unsigned char* , unsigned long long);
    bool (*Load3)(unsigned char* );
    bool (*Save1)(char32_t* );
    bool (*Save2)(unsigned char** , unsigned long long* );
    bool (*Save3)(unsigned char* );
    void (*Unk_07)(void);
    bool (*RegisterFixedString)(char32_t* );
    bool (*RegisterSaveObject)(char32_t* );
    bool (*ChangeObject)(char32_t* );
    unsigned int (*GetLinkIDFromObject)(char32_t* );
    void (*SaveLinkID)(char32_t* );
    bool (*LoadHeader)(void);
    void (*SaveHeader)(void);
    bool (*LoadStream)(void);
    void (*SaveStream)(void);
    void (*RegisterObjects)(void);
    void (*LoadTopLevelObjects)(void);
    void (*SaveTopLevelObjects)(void);
    bool (*LoadObject)(void);
    unsigned long long (*PreSaveObjectSizeTable)(void);
    bool (*SaveObjectSizeTable)(unsigned long long);
    bool (*LoadObjectSizeTable)(void);
};
static_assert(sizeof(NiStream_vtbl) == 192, "NiStream_vtbl layout differs from the PDB");
