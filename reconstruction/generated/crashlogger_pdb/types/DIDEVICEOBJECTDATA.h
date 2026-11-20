// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DIDEVICEOBJECTDATA; size 0x18
#pragma once
struct DIDEVICEOBJECTDATA {
    unsigned int ofs;
    unsigned int data;
    unsigned int timeStamp;
    unsigned int sequence;
    unsigned long long appData;
};
static_assert(sizeof(DIDEVICEOBJECTDATA) == 24, "DIDEVICEOBJECTDATA layout differs from the PDB");
