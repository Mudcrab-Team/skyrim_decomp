// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTCommonLLMessageQueue<RE::BSScript::Internal::FunctionMessage>; size 0x28
#pragma once

#include "BSTCommonMessageQueue_RE__BSScript__Internal__FunctionMessage_dc974f17.h"
struct BSTFreeListElem_RE__BSScript__Internal__FunctionMessage_acb5625f;
struct BSTFreeList_RE__BSScript__Internal__FunctionMessage_6e46ff95;
struct BSTCommonLLMessageQueue_RE__BSScript__Internal__FunctionMessage_6acb7a62 {
    BSTCommonMessageQueue_RE__BSScript__Internal__FunctionMessage_dc974f17 _base;
    BSTFreeList_RE__BSScript__Internal__FunctionMessage_6e46ff95* freeList;
    BSTFreeListElem_RE__BSScript__Internal__FunctionMessage_acb5625f* head;
    BSTFreeListElem_RE__BSScript__Internal__FunctionMessage_acb5625f** tail;
};
static_assert(sizeof(BSTCommonLLMessageQueue_RE__BSScript__Internal__FunctionMessage_6acb7a62) == 40, "BSTCommonLLMessageQueue_RE__BSScript__Internal__FunctionMessage_6acb7a62 layout differs from the PDB");
