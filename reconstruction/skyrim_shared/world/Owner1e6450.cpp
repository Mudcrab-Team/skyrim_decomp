// Source exposure: mixed. Drafted from local listings of the pinned image
// with types from the header beside this file.
// Code origin: original reconstruction from binary analysis; names from CommonLibSSE-NG (MIT) and powerof3/CommonLibSSE (GPL-3.0); no external implementation body is copied Stamped as a twin of matched 0x2bb150 (skyrim_shared/world/TESObjectCELL): source copied, names replaced by placeholders.
// The names CreateDuplicateForm and IsParentForm come from powerof3/CommonLibSSE 654e55f, which is GPL-3.0; that licence applies to those functions.
// 0x1e6450 Owner1e6450::Function1e6450
#include "Owner1e6450.h"

// guess: same compiled code as matched 0x2bb150 apart from relocated fields; its role here is not established.
void Owner1e6450::Function1e6450(bool a_set)
{
    if (a_set) {
        formFlags |= 0x400;
    } else {
        formFlags &= ~0x400;
    }
}
