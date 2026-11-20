// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Node; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct ActiveEffect;
struct Node {
    ActiveEffect* item;
    Node* next;
};
static_assert(sizeof(Node) == 16, "Node layout differs from the PDB");
