// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: va_list; size 0x1
#pragma once
struct va_list {
    unsigned char _pad_0[1];
};
static_assert(sizeof(va_list) == 1, "va_list layout differs from the PDB");
