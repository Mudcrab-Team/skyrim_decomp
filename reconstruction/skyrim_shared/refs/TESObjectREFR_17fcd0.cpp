// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// 0x17fcd0 TESObjectREFR::sub_1401337A0
// Adapted bodies: none
#include "TESObjectREFR_17fcd0.h"

// Invoke virtual slot 0x6C on this reference if its spin lock can be acquired immediately.
void TESObjectREFR::sub_1401337A0(void* arg1, bool arg2)
{
    if (lock90.TryLock()) {
        Virtual6C(arg1, arg2);
        lock90.Unlock();
    }
}
