// Source exposure: mixed (community-generated name and local binary analysis).
// Code origin: original reconstruction from the assigned local pack; no adapted body.
// HavokTaskQueueCriticalSection, g_havokTaskQueue, g_havokTaskQueueTlsIndex: GUESS(low); local lock stand-ins.
// EnterHavokTaskQueueCriticalSection_1409C6B70: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xaa2af0 HavokTaskQueueCriticalSection::EnterHavokTaskQueueCriticalSection_1409C6B70
#include "HavokTaskQueueCriticalSection_aa2af0.h"
void HavokTaskQueueCriticalSection::EnterHavokTaskQueueCriticalSection_1409C6B70()
{
    auto* queue = g_havokTaskQueue;
    if (static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(TlsGetValue(g_havokTaskQueueTlsIndex))) == 0x23df4554) {
        ++queue->recursionCount;
    } else {
        EnterCriticalSection(queue->nativeCriticalSection);
        queue->recursionCount = 1;
        TlsSetValue(g_havokTaskQueueTlsIndex, reinterpret_cast<void*>(0x23df4554));
    }
}
