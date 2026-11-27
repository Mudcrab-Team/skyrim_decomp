// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// 0x612060 SmallBufferCallable::Reset
// Adapted bodies: none
#include "SmallBufferCallable_612060.h"

// Destroys the active small-buffer callable implementation and clears the pointer.
void SmallBufferCallable::Reset()
{
    if (impl) {
        impl->DeleteThis(impl != static_cast<const void*>(this));
        impl = nullptr;
    }
}
