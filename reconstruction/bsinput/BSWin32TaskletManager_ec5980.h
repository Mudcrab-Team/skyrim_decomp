// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSWin32TaskletManager: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionec5980: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// ThreadStateEc5980, ExitTaskThread: GUESS(low) STANDIN; task-thread shutdown
struct ThreadStateEc5980 { void Finish(); };
extern "C" __declspec(dllimport) __declspec(noreturn) void ExitTaskThread(unsigned);

class BSWin32TaskletManager
{
public:
    std::uint8_t unknown00[0x10];
    ThreadStateEc5980 state;
    void Stop();

    void Functionec5980();
};
