// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// hkSolverAllocator: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// ~hkSolverAllocator: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Base10e08b0, Critical10e08b0, DeleteAllocatorLock: GUESS(low) STANDIN; allocator base and lock lifetime
class Base10e08b0 { public: virtual ~Base10e08b0(); std::uint8_t unknown08[0x438]; };
struct Critical10e08b0;
extern "C" __declspec(dllimport) void DeleteAllocatorLock(Critical10e08b0*);
struct Critical10e08b0 { std::uint8_t unknown00[40]; ~Critical10e08b0() { DeleteAllocatorLock(this); } };

class hkSolverAllocator : public Base10e08b0
{
public:
    Critical10e08b0 lock;

     ~hkSolverAllocator() override;
};
