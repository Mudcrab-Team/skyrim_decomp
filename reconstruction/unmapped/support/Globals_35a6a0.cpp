// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_0051e2f0::Func0051e2f0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00500000_o2.cpp:4942
// 0x35a6a0 f3m_0051e2f0::Func0051e2f0
// Adapted helpers: Token
#include "Globals_35a6a0.h"

namespace f3m_0051e2f0 {
bool Func0051e2f0(ScriptContext* context, int index, void* owner,
                          void* arg3, void* arg4, void* arg5, double* result,
                          char** cursor)
{
    char* text = 0;
    if (!Func00517950(context, index, cursor, owner, arg3, arg4, arg5, &text))
        return false;
    return Func0050eb80(owner, text, 0, result);
}
}
