// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none.
// 0x63a2e0 BGSSaveGameBuffer::GetActor
// 0x63a2f0 BGSSaveGameBuffer::GetForm
// 0x63a300 BGSSaveGameBuffer::GetReference
#include "BGSSaveGameBuffer.h"

// GetActor: the target returns a null pointer.
Actor* BGSSaveGameBuffer::GetActor()
{
    return nullptr;
}

// GetForm: the target returns a null pointer.
TESForm* BGSSaveGameBuffer::GetForm()
{
    return nullptr;
}

// GetReference: the target returns a null pointer.
TESObjectREFR* BGSSaveGameBuffer::GetReference()
{
    return nullptr;
}
