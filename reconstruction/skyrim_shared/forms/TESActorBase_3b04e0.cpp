// Source exposure: mixed (local binary analysis, community declarations and the cited sibling).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x3b04e0 TESActorBase::RemoveChange
// Adapted bodies: TESActorBase::RemoveChange follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesactorbase.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesactorbase.cpp:260
#include "TESActorBase_3b04e0.h"

void TESActorBase::RemoveChange(std::uint32_t a_changeFlags)
{
    if (TESDataHandler::singleton->IsTemporaryFormID(formID) &&
        gBGSSaveLoadGame->ShouldRemoveChanges(this)) {
        actorData.ClearChangeFlags(a_changeFlags);
    } else {
        TESForm::RemoveChange(a_changeFlags);
    }
}
