// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSIStream; size 0x20
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "BSTSmartPointer_RE__BSResource__Stream_f5000d46.h"
struct BSIStream_vtbl;
struct BSIStream {
    BSIStream_vtbl* __vftable;
    BSTSmartPointer_RE__BSResource__Stream_f5000d46 stream;
    bool eof;
    unsigned char pad11[7];
    BSFixedString_char_83b572b4 name;
};
static_assert(sizeof(BSIStream) == 32, "BSIStream layout differs from the PDB");
