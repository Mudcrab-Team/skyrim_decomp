// Source exposure: mixed (binary-analysis and community-headers).
// Drafted by GPT-6.1 Sol high; original reconstruction of an owning-pointer guard.
// BSReleaseOwner, reference: GUESS(low) STANDIN
#pragma once
#include "BSHandleRefObject.h"
struct BSReleaseOwner {
    p145::NiRefObject* reference;
    ~BSReleaseOwner() { if (reference) reference->DecRefCount(); }
};
