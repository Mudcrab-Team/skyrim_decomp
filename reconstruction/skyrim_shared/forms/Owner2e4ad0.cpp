// Source exposure: mixed. Drafted from local listings of the pinned image
// Code origin: Stamped as a twin of matched 0x2e4ac0 (skyrim_shared/forms/TESForm): source copied, names replaced by placeholders.
// with types from the header beside this file.
// 0x2e4ad0 Owner2e4ad0::Function2e4ad0
#include "Owner2e4ad0.h"
#include <typeinfo>

// guess: same compiled code as matched 0x2e4ac0 apart from relocated fields; its role here is not established.
bool Owner2e4ad0::Function2e4ad0() const
{
    return (formFlags & RecordFlags::kPersistent) != 0;
}
