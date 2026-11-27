// Source exposure: mixed (names from the community PDB table where labelled; the pinned image listing).
// Code origin: original; written from the listing and community PDB name.
// Adapted bodies: none
// 0x1178cc0 DebugText::PrintX
#include "DebugText_1178cc0.h"

// Forwards a variadic print call to virtual slot 5 with a null context.
void DebugText::PrintX(int a_arg1, int a_arg2, int a_arg3, const char* a_fmt, ...)
{
    std::va_list args;
    va_start(args, a_fmt);
    VPrintX(a_arg1, a_arg2, a_arg3, a_fmt, args, nullptr);
    va_end(args);
}
