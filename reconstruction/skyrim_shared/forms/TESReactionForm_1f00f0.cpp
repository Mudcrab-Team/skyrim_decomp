// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listing of the
// pinned image. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
// Code origin: original reconstruction from the pinned image listing; names as labelled below.
// 0x1f0370 TESReactionForm::GetFactionCombatRelation
// 0x1f00f0 TESReactionForm::GetReaction
#include "TESReactionForm_1f00f0.h"

std::int32_t TESReactionForm::GetFactionCombatRelation(TESForm* a_form)
{
    if (a_form) {
        for (auto* node = &reactions; node; node = node->next) {
            auto* entry = node->item;
            if (!entry) {
                break;
            }
            if (entry->form == a_form) {
                return entry->fightReaction;
            }
        }
    }
    return 0;
}

std::int32_t TESReactionForm::GetReaction(TESForm* a_form)
{
    if (a_form) {
        for (auto* node = &reactions; node; node = node->next) {
            auto* entry = node->item;
            if (!entry) {
                break;
            }
            if (entry->form == a_form) {
                return entry->reaction;
            }
        }
    }
    return 0;
}
