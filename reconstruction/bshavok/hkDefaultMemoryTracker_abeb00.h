// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// hkDefaultMemoryTracker: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionabeb00: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Tableabeb00, Lockabeb00, EnterTrackerLock, LeaveTrackerLock: GUESS(low) STANDIN; synchronized tracker lookup
struct Tableabeb00 { std::uint8_t unknown00[0x30]; void* Find(void*, unsigned); };
struct Lockabeb00 { std::uint8_t unknown00[40]; };
extern "C" __declspec(dllimport) void EnterTrackerLock(Lockabeb00*);
extern "C" __declspec(dllimport) void LeaveTrackerLock(Lockabeb00*);

class hkDefaultMemoryTracker
{
public:
    std::uint8_t unknown00[0xa0];
    Tableabeb00 table;
    Lockabeb00 lock;

    void* Functionabeb00(void* key);
};
