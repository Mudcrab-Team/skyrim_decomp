// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ScriptData; size 0x6
#pragma once
struct ScriptData {
    unsigned short opcode;
    unsigned short chunkSize;
    unsigned short numParams;
};
static_assert(sizeof(ScriptData) == 6, "ScriptData layout differs from the PDB");
