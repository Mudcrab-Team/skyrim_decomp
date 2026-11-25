// Source exposure: binary-analysis
// Code origin: original reconstruction from the local image.
// Debugger, BreakIfPresent: GUESS(low)
// IsDebuggerPresent, DebugBreak: OBSERVED
#pragma once

extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent();
extern "C" __declspec(dllimport) void __stdcall DebugBreak();

class Debugger
{
public:
    static void BreakIfPresent();
};
