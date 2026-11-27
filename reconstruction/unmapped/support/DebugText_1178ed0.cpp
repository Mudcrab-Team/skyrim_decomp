// Source exposure: mixed (names from the community PDB table where labelled; the pinned image listing).
// Code origin: original; written from the listing and community PDB name.
// Adapted bodies: none
// 0x1178ed0 DebugText::Func9_140ED1C90
#include "DebugText_1178ed0.h"

// Forwards a variadic print call with context and default flags to virtual slot 5.
void DebugText::Func9_140ED1C90(int a_arg1, void* a_context, const char* a_fmt, ...)
{
    std::va_list args;
    va_start(args, a_fmt);
    VPrintX(a_arg1, 0, 1, a_fmt, args, a_context);
    va_end(args);
}
