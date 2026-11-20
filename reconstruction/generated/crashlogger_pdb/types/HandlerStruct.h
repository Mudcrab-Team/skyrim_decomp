// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HandlerStruct; size 0x10
#pragma once
struct HandlerStruct {
    unsigned char handler_raw[8];
    void* userData;
};
static_assert(sizeof(HandlerStruct) == 16, "HandlerStruct layout differs from the PDB");
