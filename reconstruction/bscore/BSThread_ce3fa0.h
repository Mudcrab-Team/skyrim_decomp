// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// BSThread: CRASHLOGGER_PDB(59818@2026.10.24)
// BSThread::ctor: CRASHLOGGER_PDB(59818@2026.10.24)
// BSThread: GUESS(low); placeholder name
#pragma once

extern void(* Data00fdf054)(void*);

struct BSThreadCriticalSectionPC;

class BSThreadCriticalSectionPC
{
public:
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
};

class ctor
{
public:
    enum StackSize  // values: Xbox PDB ctor::StackSize
    {
        INHERIT_MAIN = 0,
        SMALL_STACK_SIZE = 16384,
        MEDIUM_STACK_SIZE = 32768,
        LARGE_STACK_SIZE = 65536,
        MAINTHREAD_STACK_SIZE = 131072
    };

    ctor();
    virtual ~ctor();
    virtual unsigned int ThreadProc();

    void Initialize(StackSize aeStackSize, const char* apName, bool bSuspend);
    void Initialize(int aeStackSize, const char* apName, bool bSuspend);
    void SetThreadPriority(int aiPriority);
    void SetSchedulingPriority(unsigned int priority);
    void SetSchedulingPriority(int priority);
    void SetName(const char* apName);
    void SetPriority(int priority);
    void Wakeup();
    void Run();
    unsigned int GetThreadID();
    bool TESAnimGroup_GetDecal();
    void Func00aa6430(int aeStackSize, const char* apName, bool bSuspend);
    void Func00aa6540(const char* apName);
    void Func00aa6550(unsigned int priority);
    void Func00aa6550(int priority);
    void Func00aa6560(int aiPriority);

    BSThreadCriticalSectionPC CriticalSection;
    void* m_pThreadHandle;
    void* m_pCurrentThreadHandle;
    unsigned int m_uiCreatedThreadId;
    unsigned int m_uiCurrentThreadId;
    bool m_bThreadStarted;
    unsigned char unk2D[3];
};

struct BSThread
{
};
