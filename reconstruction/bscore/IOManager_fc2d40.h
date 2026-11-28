// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// IOManager, sub_140D29580: CRASHLOGGER_PDB(59818@2026.10.24)
// BSAtomicCounter, IOTaskEntry, Decrement, value, unk00, unk08, task, RemoveTask, GetTaskIndex, taskCounts, totalTaskCount, Unk_01..Unk_07: GUESS(low) STANDIN
#pragma once

#include <cstdint>
#include <intrin.h>

struct BSAtomicCounter
{
    void Decrement()
    {
        // hot path: atomic decrement of a shared task counter across worker threads
        _InterlockedDecrement(&value);
    }

    // volatile: updated via interlocked operations across I/O worker threads
    volatile long value;  // 00
};
static_assert(sizeof(BSAtomicCounter) == 0x4, "BSAtomicCounter size");

struct IOTaskEntry
{
    std::uint64_t unk00;  // 00
    std::uint64_t unk08;  // 08
    void*         task;   // 10
};

class IOManager
{
public:
    virtual ~IOManager();
    virtual void          Unk_01();
    virtual void          Unk_02();
    virtual void          Unk_03();
    virtual void          Unk_04();
    virtual bool          RemoveTask(void* task);    // 28
    virtual void          Unk_06();
    virtual void          Unk_07();
    virtual std::uint32_t GetTaskIndex(void* task);  // 40

    bool sub_140D29580(IOTaskEntry* entry);

    std::uint64_t    unk08[21];       // 08
    BSAtomicCounter* taskCounts;      // B0
    BSAtomicCounter  totalTaskCount;  // B8
};
static_assert(sizeof(IOManager) == 0xC0, "IOManager size");
