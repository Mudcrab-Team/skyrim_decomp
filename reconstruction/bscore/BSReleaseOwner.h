// Source exposure: mixed (binary-analysis and community-headers).
// BSReleaseOwner, reference: GUESS(low) STANDIN
#pragma once
#include "BSHandleRefObject.h"
struct BSReleaseOwner {
    p145::NiRefObject* reference;
    ~BSReleaseOwner() { if (reference) reference->DecRefCount(); }
};
