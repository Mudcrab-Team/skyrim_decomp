// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
// 0x7e8b50 Explosion::GetMagicCaster
// 0x7e5720 Explosion::FinishLoadGame
// 0x64cea0 Explosion::SetActorCause
// 0x7e9ca0 Explosion::~Explosion
#include "Explosion.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
Explosion::Explosion()
{
}

// RVA 0x7e8b50, 21 bytes, Explosion::GetMagicCaster.
// The caster lives inside the holder; a missing holder yields no caster.
MagicCaster* Explosion::GetMagicCaster(MagicSystem::CastingSource /*a_source*/)
{
    return (holder110 != nullptr) ? &holder110->caster : nullptr;
}

// RVA 0x7e5720, 34 bytes, Explosion::FinishLoadGame.
void Explosion::FinishLoadGame()
{
    PrepareLoadState();
    AddExplosionToManager(g_explosionManager, this);
}

// RVA 0x64cea0, 41 bytes, Explosion::SetActorCause.
// The new cause gains a reference and the previous one is released; an unchanged cause does nothing.
void Explosion::SetActorCause(ActorCause* a_cause)
{
    ActorCause* previous = cause108;
    if (previous == a_cause) {
        return;
    }

    if (a_cause != nullptr) {
        // the cause is shared with other threads that hold it, so the count changes atomically
        _InterlockedIncrement(&a_cause->refCount);
    }
    cause108 = a_cause;

    if (previous != nullptr) {
        ReleaseActorCause(previous);
    }
}

// Accepted leaf retained from the integrated version.
// GetActorCause: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
void* Explosion::GetActorCause() const
{
    return cause108;
}
