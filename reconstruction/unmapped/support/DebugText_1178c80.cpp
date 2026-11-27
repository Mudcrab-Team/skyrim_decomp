// Source exposure: mixed (names from the community PDB table where labelled; the pinned image listing).
// Code origin: original; written from the listing and community PDB name.
// Adapted bodies: none
// 0x1178c80 DebugText::Func4_140ED1A40
#include "DebugText_1178c80.h"

// Forwards a variadic print call with default flags and null context to virtual slot 5.
void DebugText::Func4_140ED1A40(int a_arg1, const char* a_fmt, ...)
{
    std::va_list args;
    va_start(args, a_fmt);
    VPrintX(a_arg1, 0, 1, a_fmt, args, nullptr);
    va_end(args);
}
