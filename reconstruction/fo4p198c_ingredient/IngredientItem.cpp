// Source exposure: mixed (local target analysis, public declarations and permitted sibling).
// Origin: reconstructed from target and sibling hints.
// names: GUESS(low); signatures and type names are hypotheses.
// IngredientItem::CopyMagicItemData: SIBLING(fo4-private@1b765c70, author-permission); adapted data copying.
// IngredientItem::Revert: SIBLING(fo4-private@1b765c70, author-permission); adapted reset.
// IngredientItem::LoadGame: SIBLING(fo4-private@1b765c70, author-permission); adapted loading.
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/IngredientItem.cpp:341
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/IngredientItem.cpp:258
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/IngredientItem.cpp:250
// IngredientItem and bases: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x14f870 IngredientItem::CopyMagicItemData
// 0x14f450 IngredientItem::Revert
// 0x14f400 IngredientItem::LoadGame
#include "IngredientItem.h"
void IngredientItem::CopyMagicItemData(MagicItem* other) {
    if (other && other->formType == formType) {
        auto* ingredient = static_cast<IngredientItem*>(other);
        data.costOverride = ingredient->data.costOverride;
        data.flags = ingredient->data.flags;
    }
}
void IngredientItem::Revert(BGSLoadFormBuffer* buffer) {
    TESForm::Revert(buffer);
    if (static_cast<std::int32_t>(buffer->oldChangeFlags) < 0) {
        gamedata.knownEffectFlags = 0;
        gamedata.playerUses = 0;
    }
}
void IngredientItem::LoadGame(BGSLoadFormBuffer* buffer) {
    TESForm::LoadGame(buffer);
    if (static_cast<std::int32_t>(buffer->changeFlags) < 0)
        buffer->LoadDataEndian(&gamedata, 4, 1);
}
