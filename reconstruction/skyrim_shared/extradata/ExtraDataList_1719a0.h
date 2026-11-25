// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1719a0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Lock1719a0, Guard1719a0, Value1719a0: GUESS(low) STANDIN; protected extra-data update
struct Lock1719a0 { void Enter(); void Leave(); };
struct Guard1719a0 { Lock1719a0* lock; Guard1719a0(Lock1719a0* value):lock(value) { lock->Enter(); } ~Guard1719a0() { if(lock) { lock->Leave(); } } };
struct Value1719a0 { void Apply(void*, void*); };

class ExtraDataList
{
public:
    std::uint8_t unknown00[0x18];
    Lock1719a0 lock;
    Value1719a0* GetByType(unsigned);

    void Function1719a0(void* first, void* second);
};
