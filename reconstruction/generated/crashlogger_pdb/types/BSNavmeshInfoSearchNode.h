// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSNavmeshInfoSearchNode; size 0x38
#pragma once

struct BSNavmeshInfo;
struct BSPathingDoor;
struct BSNavmeshInfoSearchNode {
    float g_cost;
    float h_cost;
    BSPathingDoor* door;
    BSNavmeshInfo* info;
    unsigned char pad18[8];
    BSNavmeshInfoSearchNode* parent;
    BSNavmeshInfoSearchNode* prev;
    BSNavmeshInfoSearchNode* next;
};
static_assert(sizeof(BSNavmeshInfoSearchNode) == 56, "BSNavmeshInfoSearchNode layout differs from the PDB");
