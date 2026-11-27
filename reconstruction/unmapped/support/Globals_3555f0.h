// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func0051e2f0: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

#include <string.h>

namespace f3m_0051e2f0 {
struct ScriptContext;

struct Token { char text[512]; unsigned reference; char type; unsigned opcode; unsigned local; unsigned auxiliary; Token() { reference=0; local=0; type=0; opcode=0; auxiliary=0; memset(text,0,512); } };



struct ScriptContext;

extern bool Func00517950(ScriptContext* context, int index, char** cursor,
                                 void* arg3, void* arg4, void* arg5, void* arg6,
                                 char** textOut);
extern bool Func0050eb80(void* owner, const char* text, void* unused, double* result);

}

struct Globals
{
};
