// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatBehaviorThread; size 0x198
#pragma once

#include "BSTArray_RE__CombatBehaviorThread_RE__BSTSmallArrayHeapAllocator_32_86e54f02.h"
#include "CombatBehaviorStack.h"
#include "FailState.h"
#include "Flags_fa7f7281.h"
#include "ObjectPtr.h"
#include "RE__BSTArray_RE__BSTTuple_RE__CombatBehaviorTreeNode_unsigned_int_RE__BSTSmallArrayHeap_03d6909f.h"
#include "State_675e5871.h"
struct CombatBehaviorController;
struct CombatBehaviorTreeNode;
struct CombatBehaviorThread {
    CombatBehaviorStack stack;
    RE__BSTArray_RE__BSTTuple_RE__CombatBehaviorTreeNode_unsigned_int_RE__BSTSmallArrayHeap_03d6909f stackFrame;
    unsigned int stackPos;
    unsigned int pad124;
    ObjectPtr currentContextPtr;
    CombatBehaviorTreeNode* currentNode;
    CombatBehaviorTreeNode* previousNode;
    FailState failState;
    State_675e5871 state;
    Flags_fa7f7281 flags;
    unsigned int threadID;
    CombatBehaviorController* controller;
    CombatBehaviorThread* parent;
    BSTArray_RE__CombatBehaviorThread_RE__BSTSmallArrayHeapAllocator_32_86e54f02 children;
};
static_assert(sizeof(CombatBehaviorThread) == 408, "CombatBehaviorThread layout differs from the PDB");
