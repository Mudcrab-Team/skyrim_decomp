// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled in the header
// 0x780ec0 ProcessLists::SetSystemTimeClock
// Adapted bodies: none
#include "ProcessLists_780ec0.h"

// The CRT classification functions are imported from the runtime DLL.
extern "C" __declspec(dllimport) int __cdecl _isnan(double x);
extern "C" __declspec(dllimport) int __cdecl _finite(double x);

void ProcessLists::SetSystemTimeClock(float time)
{
    g_systemTimeClock = time;
    if (time > g_systemTimeClockMax) {
        g_systemTimeClock = 0.0f;
    }
    if (_isnan(g_systemTimeClock)) {
        g_systemTimeClock = 0.0f;
    } else if (!_finite(g_systemTimeClock)) {
        g_systemTimeClock = 0.0f;
    }
}
