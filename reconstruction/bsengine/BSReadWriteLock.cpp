// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// 0xce3510 BSReadWriteLock::UnlockForRead
// 0xce3520 BSReadWriteLock::UnlockForWrite
#include "BSReadWriteLock.h"

#include <intrin.h>

void BSReadWriteLock::UnlockForRead()
{
    // atomic: readers release concurrently
    _InterlockedDecrement(reinterpret_cast<volatile long*>(&_lock));
}

void BSReadWriteLock::UnlockForWrite()
{
    if (_lock == (kLockWrite | 1)) {
        _writerThread = 0;
        // fence: clear the owner before the lock word is released
        _mm_mfence();
        // atomic: release the lock word
        _InterlockedExchange(reinterpret_cast<volatile long*>(&_lock), 0);
    } else {
        // atomic: drop one recursion level
        _InterlockedDecrement(reinterpret_cast<volatile long*>(&_lock));
    }
}
