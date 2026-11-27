// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// Adapted bodies: none
// SmallBufferCallable, SmallBufferCallable::Reset, SmallBufferCallableImpl, SmallBufferCallableImpl::DeleteThis, SmallBufferCallable::impl, SmallBufferCallable::storage: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

class SmallBufferCallableImpl
{
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void DeleteThis(bool a_deallocate);
};

// Listed as BGSSaveLoadManager::PopulateSaveList in CrashLogger PDB 59818@2026.10.24,
// kept only as a low-confidence guess because the body destroys a small-buffer callable at +0x38.
class SmallBufferCallable
{
public:
    void Reset();

    std::uint8_t storage[0x38];
    SmallBufferCallableImpl* impl;
};
static_assert(offsetof(SmallBufferCallable, impl) == 0x38, "SmallBufferCallable::impl offset");
