// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SettingCollection<RE::Setting>_vtbl; size 0x50
#pragma once
struct SettingCollection_RE__Setting__vtbl_3e68548e {
    void (*_dtor_SettingCollection)(void);
    void (*InsertSetting)(char32_t* );
    void (*RemoveSetting)(char32_t* );
    bool (*WriteSetting)(char32_t* );
    bool (*ReadSetting)(char32_t* );
    bool (*OpenHandle)(bool);
    bool (*CloseHandle)(void);
    void (*Unk_07)(void);
    void (*WriteAllSettings)(void);
    void (*ReadAllSettings)(void);
};
static_assert(sizeof(SettingCollection_RE__Setting__vtbl_3e68548e) == 80, "SettingCollection_RE__Setting__vtbl_3e68548e layout differs from the PDB");
