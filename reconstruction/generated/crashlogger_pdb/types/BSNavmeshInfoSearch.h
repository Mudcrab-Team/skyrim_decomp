// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSNavmeshInfoSearch; size 0x238
#pragma once

#include "BSTArray_RE__BSNavmeshInfoSearchNode_RE__BSTSmallArrayHeapAllocator_176_4abea91e.h"
#include "NiPoint3.h"
struct BSNavmeshInfoSearchNode;
struct BSNavmeshInfoSearch_vtbl;
struct BSPathingDoor;
struct BSNavmeshInfoSearch {
    BSNavmeshInfoSearch_vtbl* __vftable;
    unsigned char pad008[272];
    BSNavmeshInfoSearchNode* savedGoalNode;
    BSNavmeshInfoSearchNode* currentNode;
    unsigned char pad128[8];
    BSTArray_RE__BSNavmeshInfoSearchNode_RE__BSTSmallArrayHeapAllocator_176_4abea91e neighbors;
    bool shouldYield;
    unsigned char pad1F1[7];
    NiPoint3 start;
    unsigned int pad204;
    void* startContext;
    NiPoint3 goal;
    unsigned int pad21C;
    BSPathingDoor* goalDoor;
    void* unk228;
    unsigned int flag230;
    bool boolResult234;
    unsigned char char235;
    unsigned short pad236;
};
static_assert(sizeof(BSNavmeshInfoSearch) == 568, "BSNavmeshInfoSearch layout differs from the PDB");
