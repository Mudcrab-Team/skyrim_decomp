// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BGSAbilityPerkEntry: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
// 0x3984c0 BGSAbilityPerkEntry::GetType
#include "BGSAbilityPerkEntry.h"
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint32_t BGSAbilityPerkEntry::GetType() const
{
    return 0x1;
}

// BGSAbilityPerkEntry::ApplyPerkEntry: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
void BGSAbilityPerkEntry::ApplyPerkEntry(Actor* a_actor)
{
    if (spell) {
        a_actor->AddSpell(spell);
        a_actor->ResetPerkSpells(0.0f);
    }
}

// BGSAbilityPerkEntry::RemovePerkEntry: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
void BGSAbilityPerkEntry::RemovePerkEntry(Actor* a_actor)
{
    if (spell) {
        a_actor->RemoveSpell(spell);
        a_actor->ResetPerkSpells(0.0f);
    }
}
