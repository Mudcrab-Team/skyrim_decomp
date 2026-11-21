// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: VirtualMachine; size 0x9518
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSScript__Internal__CodeTasklet_e3d14a6e.h"
#include "BSTArray_RE__BSScript__Internal__FunctionMessage_1ed70efe.h"
#include "BSTArray_RE__BSScript__Internal__SuspendedStack_c196ce6e.h"
#include "BSTArray_RE__BSScript__Internal__VirtualMachine__QueuedUnbindRefs_71b8dd4a.h"
#include "BSTArray_RE__BSTSmartPointer_RE__BSScript__Array_02b83150.h"
#include "BSTArray_RE__BSTSmartPointer_RE__BSScript__ObjectTypeInfo_29bad894.h"
#include "BSTArray_RE__BSTSmartPointer_RE__BSScript__Object_d59f8a95.h"
#include "BSTCommonLLMessageQueue_RE__BSScript__Internal__FunctionMessage_6acb7a62.h"
#include "BSTCommonStaticMessageQueue_RE__BSScript__Internal__SuspendedStack_128_a2cee8ea.h"
#include "BSTEventSource_RE__BSScript__StatsEvent_0258e4ce.h"
#include "BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_18371206.h"
#include "BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_56be95b9.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_0001a18c.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_6bb29944.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_8a77dec6.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_b00930f0.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_e9ad372b.h"
#include "BSTStaticFreeList_RE__BSScript__Internal__FunctionMessage_1024_eeca9e64.h"
#include "FreezeState.h"
#include "IVMDebugInterface.h"
#include "IVMObjectBindInterface.h"
#include "IVMSaveLoadInterface.h"
#include "IVirtualMachine.h"
#include "LinkerProcessor.h"
#include "ReadableStringTable.h"
#include "WritableStringTable.h"
struct ErrorLogger;
struct IFreezeQuery;
struct IMemoryPagePolicy;
struct IObjectHandlePolicy;
struct IProfilePolicy;
struct ISavePatcherInterface;
struct IStackCallbackSaveInterface;
struct ObjectBindPolicy;
struct Stack;
struct VirtualMachine {
    IVirtualMachine _base;
    IVMObjectBindInterface _base_IVMObjectBindInterface;
    IVMSaveLoadInterface _base_IVMSaveLoadInterface;
    IVMDebugInterface _base_IVMDebugInterface;
    BSTEventSource_RE__BSScript__StatsEvent_0258e4ce _base_BSTEventSource_RE_BSScript_StatsEvent_;
    ErrorLogger* errorLogger;
    IMemoryPagePolicy* memoryPagePolicy;
    IObjectHandlePolicy* handlePolicy;
    ObjectBindPolicy* objectBindPolicy;
    IFreezeQuery* freezeQuery;
    IStackCallbackSaveInterface* stackCallbackSaveInterface;
    IProfilePolicy* profilePolicy;
    ISavePatcherInterface* savePatcherInterface;
    BSSpinLock typeInfoLock;
    LinkerProcessor linker;
    BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_18371206 objectTypeMap;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_0001a18c typeIDToObjectType;
    BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_56be95b9 objectTypeToTypeID;
    BSTArray_RE__BSTSmartPointer_RE__BSScript__ObjectTypeInfo_29bad894 typesToUnload;
    BSSpinLock funcQueueLock;
    BSTStaticFreeList_RE__BSScript__Internal__FunctionMessage_1024_eeca9e64 funcMsgPool;
    BSTCommonLLMessageQueue_RE__BSScript__Internal__FunctionMessage_6acb7a62 funcMsgQueue;
    BSTArray_RE__BSScript__Internal__FunctionMessage_1ed70efe overflowFuncMsgs;
    BSTArray_RE__BSScript__Internal__CodeTasklet_e3d14a6e vmTasks;
    unsigned int uiWaitingFunctionMessages;
    bool overstressed;
    bool initialized;
    unsigned short pad827E;
    BSTCommonStaticMessageQueue_RE__BSScript__Internal__SuspendedStack_128_a2cee8ea suspendQueue1;
    BSTCommonStaticMessageQueue_RE__BSScript__Internal__SuspendedStack_128_a2cee8ea suspendQueue2;
    BSTArray_RE__BSScript__Internal__SuspendedStack_c196ce6e overflowSuspendArray1;
    BSTArray_RE__BSScript__Internal__SuspendedStack_c196ce6e overflowSuspendArray2;
    BSSpinLock suspendQueueLock;
    BSTCommonStaticMessageQueue_RE__BSScript__Internal__SuspendedStack_128_a2cee8ea* stacksToResume;
    BSTArray_RE__BSScript__Internal__SuspendedStack_c196ce6e* stacksToResumeOverflow;
    BSTCommonStaticMessageQueue_RE__BSScript__Internal__SuspendedStack_128_a2cee8ea* stacksToSuspend;
    BSTArray_RE__BSScript__Internal__SuspendedStack_c196ce6e* stacksToSuspendOverflow;
    BSSpinLock runningStacksLock;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_6bb29944 allRunningStacks;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_6bb29944 waitingLatentReturns;
    unsigned int nextStackID;
    BSSpinLock frozenStacksLock;
    unsigned int pad938C;
    Stack* frozenStacks;
    unsigned int frozenStacksCount;
    FreezeState freezeState;
    BSSpinLock attachedScriptsLock;
    BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_8a77dec6 attachedScripts;
    unsigned int unk93D8;
    unsigned int unk93DC;
    BSTArray_RE__BSTSmartPointer_RE__BSScript__Object_d59f8a95 objectsAwaitingCleanup;
    BSSpinLock arraysLock;
    unsigned int nextArrayToClean;
    unsigned int pad9404;
    BSTArray_RE__BSTSmartPointer_RE__BSScript__Array_02b83150 arrays;
    BSSpinLock objectResetLock;
    BSTArray_RE__BSTSmartPointer_RE__BSScript__Object_d59f8a95 objectsAwaitingReset;
    BSSpinLock objectLock;
    BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_e9ad372b objectTable;
    BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_b00930f0 arrayTable;
    BSSpinLock queuedUnbindLock;
    BSTArray_RE__BSScript__Internal__VirtualMachine__QueuedUnbindRefs_71b8dd4a queuedUnbinds;
    unsigned char saveGameVersion;
    unsigned char undefined_94c9[3];
    unsigned int scriptCount;
    unsigned int arrayCount;
    unsigned char undefined_94d4[4];
    WritableStringTable writableStringTable;
    ReadableStringTable readableStringTable;
    BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_18371206* writeableTypeTable;
    BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_18371206* readableTypeTable;
};
static_assert(sizeof(VirtualMachine) == 38168, "VirtualMachine layout differs from the PDB");
