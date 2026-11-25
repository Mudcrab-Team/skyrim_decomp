// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function165460: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Lock165460, Guard165460: GUESS(low) STANDIN; scoped extra-data lock
struct Lock165460 { void Enter(); void Leave(); };
struct Guard165460 { Lock165460* lock; Guard165460(Lock165460* p):lock(p) { lock->Enter(); } ~Guard165460() { if (lock) { lock->Leave(); } } };
// Entry165460, Node165460, Extra165460: GUESS(low) STANDIN; linked extra-data payload
struct Entry165460 { void* key; unsigned char value; };
struct Node165460 { Entry165460* value; Node165460* next; };
struct Extra165460 { std::uint8_t unknown00[0x10]; Node165460* head; };

class ExtraDataList
{
public:
    std::uint8_t unknown00[0x18];
    Lock165460 lock;
    Extra165460* GetByType(unsigned);

    bool Function165460(void* key);
};
