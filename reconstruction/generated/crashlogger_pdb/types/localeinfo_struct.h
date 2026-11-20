// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: localeinfo_struct; size 0x10
#pragma once

struct threadlocaleinfostruct;
struct threadmbcinfostruct;
struct localeinfo_struct {
    threadlocaleinfostruct* locinfo;
    threadmbcinfostruct* mbcinfo;
};
static_assert(sizeof(localeinfo_struct) == 16, "localeinfo_struct layout differs from the PDB");
