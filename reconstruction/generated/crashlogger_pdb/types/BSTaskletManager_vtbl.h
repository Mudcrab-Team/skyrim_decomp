// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTaskletManager_vtbl; size 0x50
#pragma once
struct BSTaskletManager_vtbl {
    void (*_dtor_BSTaskletManager)(void);
    void (*Unk_01)(void);
    void (*ShutdownAllTasks)(void);
    bool (*IsWorkerThread)(unsigned int);
    bool (*CreateTaskGroupData)(char32_t** );
    bool (*BeginTaskGroup)(char32_t* );
    bool (*AddTasklet)(char32_t* , char32_t* , bool);
    bool (*CloseTaskGroupData)(char32_t* );
    void (*ReleaseTaskletData)(char32_t* );
    void (*Unk_09)(void);
};
static_assert(sizeof(BSTaskletManager_vtbl) == 80, "BSTaskletManager_vtbl layout differs from the PDB");
