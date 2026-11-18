// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none.
// 0xfd2da0 BSXFlags::CreateClone
// 0xfd2de0 BSXFlags::RegisterStreamables
// 0xfd30c0 BSXFlags::~BSXFlags
#include "BSXFlags.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSXFlags::BSXFlags()
{
}

// The clone is the object itself; the listing returns its first argument unchanged.
NiObject* BSXFlags::CreateClone(NiCloningProcess& a_cloning)
{
    return this;
}

// The listing calls the base stream check on this object and returns its negation.
// NiObject::StreamCanSkip: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the direct call to the base form is inferred from the listing
bool BSXFlags::RegisterStreamables(NiStream& a_stream)
{
    return !NiObject::StreamCanSkip();
}

// Compared as the scalar deleting destructor; the base destructor runs first, then the object is freed
// when the delete flag is set.
BSXFlags::~BSXFlags()
{
}
