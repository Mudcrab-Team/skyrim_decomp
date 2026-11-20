// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IVMSaveLoadInterface_vtbl; size 0xb8
#pragma once
struct IVMSaveLoadInterface_vtbl {
    void (*_dtor_IVMSaveLoadInterface)(void);
    void (*SaveGame)(char32_t* , char32_t* , bool);
    void (*LoadGame)(char32_t* , char32_t* );
    void (*MarkSaveInvalid)(char32_t* );
    unsigned char (*GetSaveGameVersion)(void);
    void (*CleanupSave)(void);
    void (*Unk_06)(void);
    void (*DropAllRunningData)(void);
    void (*Unk_08)(void);
    void (*Unk_09)(void);
    void (*Unk_0A)(void);
    void (*Unk_0B)(void);
    void (*Unk_0C)(void);
    void (*Unk_0D)(char32_t* , char32_t** );
    void (*Unk_0E)(char32_t* , void* );
    bool (*GetStackByID)(char32_t* , char32_t** );
    void (*GetWritableStringTable)(void);
    void (*GetWritableStringTable2)(void);
    void (*GetReadableStringTable)(void);
    char32_t*(*GetWritableTypeTable)(void);
    char32_t*(*GetWritableTypeTable2)(void);
    char32_t*(*GetReadableTypeTable)(void);
    bool (*CreateEmptyTasklet)(char32_t* , char32_t** );
};
static_assert(sizeof(IVMSaveLoadInterface_vtbl) == 184, "IVMSaveLoadInterface_vtbl layout differs from the PDB");
