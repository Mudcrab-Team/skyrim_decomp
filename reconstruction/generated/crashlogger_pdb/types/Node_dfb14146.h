// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Node; size 0x10
// one of 2 different PDB types sharing this name
#pragma once
struct Node_dfb14146 {
    unsigned char* item;
    unsigned char next_raw[8];
};
static_assert(sizeof(Node_dfb14146) == 16, "Node_dfb14146 layout differs from the PDB");
