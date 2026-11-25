// Source exposure: mixed (local pinned-image analysis and community-generated names).
// Code origin: original reconstruction from the contributor-owned image.
// PushQueueEntry: CRASHLOGGER_PDB(59818@2026.10.24)
// CullQueue, CullEntry, slots, slotMask, readClaim, readComplete, writeComplete, writeClaim: GUESS(low) STANDIN
#pragma once

struct CullEntry;
struct CullQueue {
    static constexpr unsigned int slotMask = 8191;
    CullEntry* slots[slotMask + 1];
    volatile long readClaim;
    volatile long readComplete;
    volatile long writeComplete;
    volatile long writeClaim;
    CullEntry* PopFreeQueueEntry();
    void PushQueueEntry(CullEntry* entry);
};

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long milliseconds);
