// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: XAPO_REGISTRATION_PROPERTIES; size 0x42c
#pragma once

#include "GUID.h"
struct XAPO_REGISTRATION_PROPERTIES {
    GUID clsid;
    unsigned short friendlyName[256];
    unsigned short copyrightInfo[256];
    unsigned int majorVersion;
    unsigned int minorVersion;
    unsigned int flags;
    unsigned int minInputBufferCount;
    unsigned int maxInputBufferCount;
    unsigned int minOutputBufferCount;
    unsigned int maxOutputBufferCount;
};
static_assert(sizeof(XAPO_REGISTRATION_PROPERTIES) == 1068, "XAPO_REGISTRATION_PROPERTIES layout differs from the PDB");
