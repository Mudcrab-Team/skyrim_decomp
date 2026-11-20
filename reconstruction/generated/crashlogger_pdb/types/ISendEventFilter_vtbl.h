// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ISendEventFilter_vtbl; size 0x8
#pragma once
struct ISendEventFilter_vtbl {
    bool (*matchesFilter)(char32_t* );
};
static_assert(sizeof(ISendEventFilter_vtbl) == 8, "ISendEventFilter_vtbl layout differs from the PDB");
