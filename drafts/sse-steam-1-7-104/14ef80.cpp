// Near miss: 56.16% | inline-set
// Exposure detail: (local target analysis and community declarations).
// Source exposure: mixed
// Code origin: original reconstruction from target observations and attributed community material.
// Adapted bodies: IngredientItem::LearnNextEffect and LearnEffect from CommonLibSSE-NG b93280e, src/RE/I/IngredientItem.cpp, MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// IngredientItem, LearnNextEffect, LearnEffect, knownEffectFlags, virtual names: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declarations and name hints.
// Body source: adapted LearnNextEffect/LearnEffect, src/RE/I/IngredientItem.cpp at b93280e (MIT); return convention and layout independently checked locally.
// unknown08: GUESS(low); unaccessed range.
// 0x14ef80 IngredientItem::LearnNextEffect

#include "include/14ef80/IngredientItem_14ef80.h"

// Discover the first effect whose knowledge bit has not been set.
std::uint32_t IngredientItem::LearnNextEffect()
{
    std::uint16_t flags = knownEffectFlags;
    std::uint32_t index = 0;
    while ((flags & (1u << index)) != 0) {
        if (++index >= 4) {
            return 0xFFFFFFFFu;
        }
    }
    LearnEffect(index);
    return index;
}
