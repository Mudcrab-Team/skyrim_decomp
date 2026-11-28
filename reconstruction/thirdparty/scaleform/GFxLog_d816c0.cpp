// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// Adapted bodies: none
// 0xd816c0 GFxLogBase<GFxLog>::LogScriptError
#include "GFxLog_d816c0.h"

// Formats and dispatches a script error log message through the derived GFxLog state base.
// The CrashLogger list names the derived class; this is written as the member of its template base.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
template <>
void GFxLogBase<GFxLog>::LogScriptError(const char* fmt, ...)
{
    std::va_list args;
    va_start(args, fmt);
    static_cast<GFxLog*>(this)->LogMessageVarg(0x11, fmt, args);
    va_end(args);
}
