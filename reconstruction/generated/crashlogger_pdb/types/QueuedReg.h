// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: QueuedReg; size 0x10
#pragma once

struct MenuEventHandler;
struct QueuedReg {
    MenuEventHandler* handler;
    bool add;
    unsigned char pad08;
    unsigned short pad09;
    unsigned int pad0A;
};
static_assert(sizeof(QueuedReg) == 16, "QueuedReg layout differs from the PDB");
