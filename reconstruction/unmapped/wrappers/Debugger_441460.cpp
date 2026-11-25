// Source exposure: binary-analysis
// Code origin: original reconstruction from the local image.
// Adapted bodies: none
// 0x441460 Debugger::BreakIfPresent
#include "Debugger_441460.h"

void Debugger::BreakIfPresent()
{
    if (IsDebuggerPresent() == 1) {
        DebugBreak();
    }
}
