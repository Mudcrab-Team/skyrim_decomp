// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSResourceNiBinaryStream; size 0x38
#pragma once

#include "BSTSmartPointer_RE__BSResource__Stream_f5000d46.h"
#include "ErrorCode.h"
#include "NiBinaryStream.h"
struct BufferType;
struct BSResourceNiBinaryStream {
    NiBinaryStream _base;
    BSTSmartPointer_RE__BSResource__Stream_f5000d46 stream;
    BufferType* buffer;
    unsigned int streamPos;
    ErrorCode lastError;
};
static_assert(sizeof(BSResourceNiBinaryStream) == 56, "BSResourceNiBinaryStream layout differs from the PDB");
