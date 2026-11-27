// Source exposure: mixed (names from the community PDB table where labelled; the pinned image listing).
// Code origin: original; written from the listing and community PDB name.
// Adapted bodies: none
// 0x1178dd0 DebugText::Func6_140ED1B90
#include "DebugText_1178dd0.h"

// Forwards a variadic formatted print call to virtual slot 7 with a null context.
void DebugText::Func6_140ED1B90(int a_x, int a_y, const char* a_fmt, ...)
{
    std::va_list args;
    va_start(args, a_fmt);
    VPrint(a_x, a_y, a_fmt, args, nullptr);
    va_end(args);
}
