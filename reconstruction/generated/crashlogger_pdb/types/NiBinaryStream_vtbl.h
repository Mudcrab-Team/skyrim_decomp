// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiBinaryStream_vtbl; size 0x30
#pragma once

struct BufferInfo;
struct NiBinaryStream_vtbl {
    void (*_dtor_NiBinaryStream)(void);
    bool (*good)(void);
    void (*seek)(int, int);
    unsigned int (*tell)(void);
    void (*get_info)(BufferInfo* );
    void (*set_endian_swap)(bool);
};
static_assert(sizeof(NiBinaryStream_vtbl) == 48, "NiBinaryStream_vtbl layout differs from the PDB");
