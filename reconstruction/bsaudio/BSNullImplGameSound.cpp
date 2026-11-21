// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the pinned listing and the cited public declarations only.
// Adapted bodies: none.
// 0xcd6aa0 BSNullImplGameSound::Unk_08
// 0xcd6c10 BSNullImplGameSound::Functioncd6c10
#include "BSNullImplGameSound.h"

#include <new>

// Unk_08: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
std::uint8_t BSNullImplGameSound::Unk_08() const
{
    return 0x1;
}

// Functioncd6c10: GUESS(low); the listing tests bit 0 of the flag argument, calls one cleanup
// function unconditionally and calls operator delete with the class size, so the body keeps the
// cleanup call out of line and deletes only under bit 0.
BSNullImplGameSound* BSNullImplGameSound::Functioncd6c10(std::uint32_t a_flags)
{
    this->BSGameSound::~BSGameSound();
    if ((a_flags & 1u) != 0) {
        operator delete(this, sizeof(BSNullImplGameSound));
    }
    return this;
}
