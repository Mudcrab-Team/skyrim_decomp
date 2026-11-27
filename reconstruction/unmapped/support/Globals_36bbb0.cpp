// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_0052fb80::f3_0328::Func0052fb80.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00520000_o2_2.cpp:130
// 0x36bbb0 f3m_0052fb80::f3_0328::Func0052fb80
#include "Globals_36bbb0.h"

namespace f3m_0052fb80 {
namespace f3_0328 {
bool Func0052fb80(const ScriptParameter* parameters, const char* scriptData,
                               TESObjectREFR* thisObject, TESObjectREFR* container,
                               Script* script, ScriptLocals* locals, double& result,
                               unsigned int& opcodeOffset)
{
    unsigned int formID = 0;
    if (!Func00517950(parameters, scriptData, &opcodeOffset, thisObject, container,
                     script, locals, &formID))
        return false;
    return Func00513ee0(thisObject,
                                              reinterpret_cast<void*>(formID), 0, result);
}
}
}
