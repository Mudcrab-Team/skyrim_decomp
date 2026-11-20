// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IOManager_vtbl; size 0xc8
#pragma once
struct IOManager_vtbl {
    void (*_dtor_IOManager)(void);
    void (*Unk_01)(void);
    void (*Unk_02)(void);
    void (*Unk_03)(void);
    void (*Unk_04)(void);
    void (*Unk_05)(void);
    void (*Unk_06)(void);
    void (*Unk_07)(void);
    void (*Unk_08)(void);
    void (*Unk_09)(void);
    unsigned int (*Unk_10)(void);
    void (*Unk_11)(void);
    void (*Unk_12)(void);
    void (*Unk_13)(void);
    void (*Unk_14)(void);
    void (*Unk_15)(void);
    void (*Unk_16)(void);
    void (*ResubmitTask)(char32_t* );
    void (*Unk_18)(void);
    void (*Unk_19)(void);
    void (*Unk_20)(void);
    void (*Unk_21)(void);
    void (*Unk_22)(void);
    void (*Unk_23)(void);
    void (*Unk_24)(void);
};
static_assert(sizeof(IOManager_vtbl) == 200, "IOManager_vtbl layout differs from the PDB");
