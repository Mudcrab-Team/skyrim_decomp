// Source exposure: mixed (names from the community PDB table where labelled; the pinned image listing).
// Code origin: original; written from the listing and community PDB name.
// Adapted bodies: none
// 0x1178f10 DebugText::Func8_140ED1CD0
#include "DebugText_1178f10.h"

// Forwards a variadic print call with context to virtual slot 5.
void DebugText::Func8_140ED1CD0(int a_arg1, void* a_context, int a_arg2, int a_arg3, const char* a_fmt, ...)
{
    std::va_list args;
    va_start(args, a_fmt);
    VPrintX(a_arg1, a_arg2, a_arg3, a_fmt, args, a_context);
    va_end(args);
}
