// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Main: STANDIN EXE_RTTI
// Function65bfd0, TimerService, GetTimerService, StartTimer: GUESS(low)
#pragma once
#include <cstdint>
class TimerService { public: void StartTimer(std::uint32_t, std::uint32_t); };
TimerService* GetTimerService();
class Main { public: static void Function65bfd0(bool enabled); };
