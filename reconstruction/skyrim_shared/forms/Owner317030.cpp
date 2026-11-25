// Source exposure: mixed (pinned image analysis and community names).
// Code origin: Stamped as a twin of matched 0x1e88f0 (skyrim_shared/forms/TESLeveledList): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
// 0x317030 Owner317030::GetMultCalc
#include "Owner317030.h"

// guess: same compiled code as matched 0x1e88f0 apart from relocated fields; its role here is not established.
bool Owner317030::GetMultCalc()
{
    return TestBit(llFlags, 1);
}
