// Source exposure: binary-analysis
// WorldLockStorage, lockEnabled, LockRead, UnlockRead, LockWrite, UnlockWrite: GUESS(low) STANDIN; lock dispatch names remain provisional
#pragma once
#include <cstdint>
struct WorldLockStorage { std::uint32_t owner; std::uint32_t state; };
extern bool lockEnabled;
extern void LockRead(WorldLockStorage*);
extern void UnlockRead(WorldLockStorage*);
extern void LockWrite(WorldLockStorage*);
extern void UnlockWrite(WorldLockStorage*);
