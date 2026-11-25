// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1650a0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Lock1650a0, Guard1650a0: GUESS(low) STANDIN; scoped extra-data lock
struct Lock1650a0 { void Enter(); void Leave(); };
struct Guard1650a0 { Lock1650a0* lock; Guard1650a0(Lock1650a0* p):lock(p) { lock->Enter(); } ~Guard1650a0() { if (lock) { lock->Leave(); } } };
// Entry1650a0, Node1650a0, Extra1650a0: GUESS(low) STANDIN; linked extra-data payload
struct Entry1650a0 { void* key; unsigned char value; };
struct Node1650a0 { Entry1650a0* value; Node1650a0* next; };
struct Extra1650a0 { std::uint8_t unknown00[0x10]; Node1650a0* head; };

class ExtraDataList
{
public:
    std::uint8_t unknown00[0x18];
    Lock1650a0 lock;
    Extra1650a0* GetByType(unsigned);

    unsigned char Function1650a0(void* key);
};
