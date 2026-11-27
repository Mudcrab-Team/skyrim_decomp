// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_00449cb0::TESForm::Func00449cb0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00440000_o2.cpp:8880
// 0x2f9fe0 f3m_00449cb0::TESForm::Func00449cb0
#include "TESForm_2f9fe0.h"

namespace f3m_00449cb0 {
int TESForm::Func00449cb0()
{
    if (!Data0106cf3c)
    {
        Data0106cf3c = 1;
        const char* name = GetEditorName_130();
        Data0106cf3c = 0;
        if (name)
        {
            size_t len = strlen(name);
            return len;
        }
    }
    return 0;
}
}
