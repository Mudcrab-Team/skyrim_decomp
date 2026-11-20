// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: localerefcount; size 0x20
#pragma once
struct localerefcount {
    char* locale;
    wchar_t* wlocale;
    int* refcount;
    int* wrefcount;
};
static_assert(sizeof(localerefcount) == 32, "localerefcount layout differs from the PDB");
