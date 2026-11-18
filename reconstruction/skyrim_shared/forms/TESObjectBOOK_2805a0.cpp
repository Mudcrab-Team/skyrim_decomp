// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// 0x2805a0 TESObjectBOOK::Function2805a0
#include "TESObjectBOOK_2805a0.h"
void TESObjectBOOK::Function2805a0(bool flag) { BookRequest request{this, flag}; GetManager()->HandleRequest(request); }
