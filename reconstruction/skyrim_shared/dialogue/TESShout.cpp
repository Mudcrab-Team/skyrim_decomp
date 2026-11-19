// Source exposure: mixed (pinned image listing and community declarations; names from CharmedBaryon/CommonLibSSE-NG b93280e, MIT).
// Code origin: original reconstruction from the pinned image and community declarations.
// Consulted (private, not in repo): decompiler control-flow hints.
// Adapted bodies: none.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x387ea0 TESShout::GetKnown
// 0x387c90 TESShout::InitItemImpl
#include "TESShout.h"

class TESFile;

// AddCompileIndex, GetFile, LookupByID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SetFormFlag: GUESS(low)
// InitComponent30, InitComponent40: GUESS(low); component initializers called with the component and the owner
void AddCompileIndex(std::uint32_t& a_id, TESFile* a_file);
TESFile* GetFile(const TESForm* a_self, std::int32_t a_index);
TESForm* LookupByID(std::uint32_t a_formID);
void SetFormFlag(TESForm* a_form, bool a_set);
void InitComponent30(void* a_component, TESForm* a_owner);
void InitComponent40(void* a_component, TESForm* a_owner);

// TestBit: GUESS(low)
static bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

// RVA 0x387c90, 256 bytes. Skip zero ids, write null only after a nonzero lookup fails.
void TESShout::InitItemImpl()
{
    if (TestBit(formFlags, 3)) {
        return;
    }
    InitComponent30(static_cast<BGSMenuDisplayObject*>(this), this);
    InitComponent40(static_cast<BGSEquipType*>(this), this);
    for (std::uint32_t i = 0; i < 3; ++i) {
        TESForm* word = reinterpret_cast<TESForm*>(variations[i].word);
        // The loaded record keeps a form id in the pointer slot until this init step replaces it with the form.
        std::uint32_t formID = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(word));
        if (formID != 0) {
            AddCompileIndex(formID, GetFile(this, -1));
            TESForm* found = LookupByID(formID);
            if (found != nullptr && static_cast<std::uint8_t>(found->formType) == 0x76) {
                variations[i].word = reinterpret_cast<TESWordOfPower*>(found);
            } else {
                variations[i].word = nullptr;
            }
        }
        TESForm* spell = reinterpret_cast<TESForm*>(variations[i].spell);
        // Same for the spell slot: id first, form pointer after the lookup.
        formID = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(spell));
        if (formID != 0) {
            AddCompileIndex(formID, GetFile(this, -1));
            TESForm* found = LookupByID(formID);
            if (found != nullptr && static_cast<std::uint8_t>(found->formType) == 0x16) {
                variations[i].spell = reinterpret_cast<SpellItem*>(found);
            } else {
                variations[i].spell = nullptr;
            }
        }
    }
    SetFormFlag(this, true);
}

bool TESShout::GetKnown() const
{
    for (std::uint32_t i = 0; i < 3; ++i) {
        if (variations[i].word) {
            return (variations[i].word->formFlags >> 16) & 1;
        }
    }
    return false;
}
