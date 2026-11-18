// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local listings of the pinned image
// 0x1e36b0 TESForm::ClearData
// 0x2e4ac0 TESForm::IsPersistent
// 0x1e6010 TESForm::IsTemporaryFormID
// 0x1e1fd0 TESForm::GetEnchantment
// 0x1e5700 TESForm::SaveGame
// 0x1f3560 TESForm::GetGoldValue
// 0x1e5770 TESForm::LoadGame
#include "TESForm.h"

#include <typeinfo>

TESDataHandler* TESDataHandler::singleton;

void TESForm::ClearData()
{
}

bool TESForm::GetIgnoredBySandbox() const
{
    return false;
}

bool TESForm::IsHeadingMarker() const
{
    return false;
}

bool TESForm::IsFormTypeChild(FormType)
{
    return false;
}

bool TESForm::IsPersistent() const
{
    return (formFlags & RecordFlags::kPersistent) != 0;
}

bool TESForm::IsTemporaryFormID() const
{
    return TESDataHandler::singleton->IsTemporaryFormID(formID);
}

EnchantmentItem* TESForm::GetEnchantment(ExtraDataList* a_extraList)
{
    EnchantmentItem* enchantment = nullptr;
    TESEnchantableForm* enchantable = dynamic_cast<TESEnchantableForm*>(this);
    if (enchantable) {
        enchantment = enchantable->formEnchanting;
    }
    if (!enchantment && a_extraList) {
        return a_extraList->GetEnchantment();
    }
    return enchantment;
}

void TESForm::SaveGame(BGSSaveFormBuffer* a_buf)
{
    if (a_buf->unk1B & 1) {
        a_buf->SaveDataEndian(&formFlags, 4, 4, 0);
        a_buf->SaveDataEndian(&inGameFormFlags, 2, 2, 0);
    }
}

std::int32_t TESForm::GetGoldValue() const
{
    const TESValueForm* valueForm = dynamic_cast<const TESValueForm*>(this);
    if (valueForm) {
        return valueForm->value;
    }
    const MagicItem* magicItem = dynamic_cast<const MagicItem*>(this);
    if (magicItem) {
        return static_cast<std::int32_t>(magicItem->CalculateCost(nullptr));
    }
    // AlchemyItem derives from MagicItem, so this cast cannot succeed once the one above failed; the
    // image performs it all the same (its descriptor is the AlchemyItem one), so it is kept.
    const AlchemyItem* alchemyItem = dynamic_cast<const AlchemyItem*>(this);
    if (alchemyItem) {
        return static_cast<std::int32_t>(alchemyItem->CalculateCost(nullptr));
    }
    return -1;
}

// kRestoredReferenceFlags, kRestoredFormFlags, kRestoredInGameFlags: GUESS; the record flags a save
// restores for references and for other forms, and the in-game flags it restores
constexpr std::uint32_t kRestoredReferenceFlags = 0x912860;
constexpr std::uint32_t kRestoredFormFlags = 0x10860;
constexpr std::uint16_t kRestoredInGameFlags = 0x3f;

void TESForm::LoadGame(BGSLoadFormBuffer* a_buf)
{
    if (a_buf->changeFlags & ChangeFlags::kFlags) {
        std::uint32_t loadedFlags = 0;
        a_buf->LoadDataEndian(&loadedFlags, 4, 4);
        std::uint16_t loadedInGame = 0;
        a_buf->LoadDataEndian(&loadedInGame, 2, 2);
        inGameFormFlags &= ~kRestoredInGameFlags;
        inGameFormFlags |= loadedInGame & kRestoredInGameFlags;
        // keep the current bits outside the restored set and take the saved bits inside it
        if (AsReference2()) {
            formFlags = (formFlags & ~kRestoredReferenceFlags) | (loadedFlags & kRestoredReferenceFlags);
        } else {
            formFlags = (formFlags & ~kRestoredFormFlags) | (loadedFlags & kRestoredFormFlags);
        }
    }
}
