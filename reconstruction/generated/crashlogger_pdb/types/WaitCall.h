// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: WaitCall; size 0x10
#pragma once

struct IVirtualMachine;
struct WaitCall {
    unsigned int timeToSendEvent;
    unsigned int stackID;
    IVirtualMachine* vm;
};
static_assert(sizeof(WaitCall) == 16, "WaitCall layout differs from the PDB");
