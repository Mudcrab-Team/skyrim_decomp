// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1718e0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Lock1718e0, Guard1718e0: GUESS(low) STANDIN; scoped extra-data lock
struct Lock1718e0 { void Enter(); void Leave(); };
struct Guard1718e0 { Lock1718e0* lock; Guard1718e0(Lock1718e0* p):lock(p) { lock->Enter(); } ~Guard1718e0() { if (lock) { lock->Leave(); } } };
// Extra1718e0, Scope1718e0, allocationTag1718e0: GUESS(low) STANDIN; tagged extra-data removal
extern __declspec(thread) unsigned allocationTag1718e0;
struct Scope1718e0 { unsigned saved; Scope1718e0(unsigned value):saved(allocationTag1718e0) { allocationTag1718e0=value; } ~Scope1718e0() { allocationTag1718e0=saved; } };
struct Extra1718e0 { void Remove(void*); bool Empty(); };

class ExtraDataList
{
public:
    std::uint8_t unknown00[0x18];
    Lock1718e0 lock;
    Extra1718e0* GetByType(unsigned);
    void RemoveExtra(Extra1718e0*, bool);

    void Function1718e0(void* value);
};
