// Source exposure: mixed (names from the community PDB table where labelled; the pinned image listing).
// Code origin: original; written from the listing and community PDB name.
// Adapted bodies: none
// 0x1178f50 DebugText::PrintLineC
#include "DebugText_1178f50.h"

// Forwards a variadic formatted print call with context to virtual slot 7.
void DebugText::PrintLineC(void* a_context, int a_x, int a_y, const char* a_fmt, ...)
{
    std::va_list args;
    va_start(args, a_fmt);
    VPrint(a_x, a_y, a_fmt, args, a_context);
    va_end(args);
}
