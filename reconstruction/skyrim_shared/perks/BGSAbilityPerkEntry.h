// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BGSAbilityPerkEntry: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
#pragma once
#include <cstdint>

class Actor;
class SpellItem;
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class BGSAbilityPerkEntry
{
public:
    virtual std::uint32_t GetType() const;
    // ApplyPerkEntry, RemovePerkEntry: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); no base declaration in this unit, so not override
    virtual void ApplyPerkEntry(Actor* a_actor);
    virtual void RemovePerkEntry(Actor* a_actor);

    std::uint8_t unk08[0x8];  // 08
    SpellItem*   spell;       // 10
    // spell: GUESS(low)
};

// AddSpell, RemoveSpell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ResetPerkSpells: GUESS(low)
// ResetPerkSpells: the tail callee takes the actor and a float of 0.0
class Actor
{
public:
    void AddSpell(SpellItem* a_spell);
    void RemoveSpell(SpellItem* a_spell);
    void ResetPerkSpells(float a_value);
};
