// Licence: uses some member names from powerof3/CommonLibSSE (see the header), so this file is GPL-3.0.
// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local listings of the pinned image with
// types from the header beside this file.
// 0x692ea0 Character::GetRotationX
// 0x73ad70 Character::Unk_C4
// 0x73a760 Character::GetBiped2
// 0x6cc910 Character::StartDeferredKill
// 0x73a8b0 Character::Revert
// 0x73abc0 Character::~Character
// 0x67eab0 Character::SetCrimeFaction
#include "Character.h"

// The constructor is not compared: it is defined so that this unit emits the vftable and with
// it the deleting destructor, as the original unit did. ~Character itself is declared, not defined:
// the deleting destructor calls it out of line (the plain destructor lives in another unit).
Character::Character()
{
}

float Character::GetRotationX() const
{
    return unk48;
}

void Character::Unk_C4(std::uint8_t a_arg1)
{
    unk27A = a_arg1;
}

const BSTSmartPointer<BipedAnim>& Character::GetBiped2() const
{
    return biped2;
}

void Character::StartDeferredKill()
{
    if (currentProcess) {
        currentProcess->StartDeferredKill();
    }
}

void Character::Revert(BGSLoadFormBuffer* a_buf)
{
    Actor::Revert(a_buf);
    OnArmorActorValueChanged();
    unkE8 &= ~0x40000000u;
    unk279 = 0;
}

// TestBit: GUESS(low); a flag-word bit test by bit index, probably an engine flag accessor that takes the
// bit number. The word is passed by value so that the test is a shift and a mask of the loaded word.
static bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

void Character::SetCrimeFaction(TESFaction* a_faction)
{
    if (a_faction) {
        if (!TestBit(a_faction->factionFlags, 6)) {
            return;
        }
        if (!IsInFaction(a_faction)) {
            if (TestBit(unk40->actorData.actorBaseFlags, 5)) {
                unk40->actorData.AddFaction(a_faction, 1);
            } else {
                AddChange(0x80000000u);
                ExtraFactionChanges* changes = extraList.GetFactionChanges();
                if (!changes) {
                    extraList.AddFactionChanges();
                    changes = extraList.GetFactionChanges();
                }
                if (changes) {
                    changes->SetFactionRank(a_faction, 1);
                }
            }
            UpdateFactionsA(true);
            UpdateFactionsB();
            if (currentProcess && currentProcess->cachedValues) {
                currentProcess->cachedValues->flags &= ~CachedValues::kOwnerIsInCombatantFaction;
            }
        }
    }
    extraList.RemoveFactionChange(a_faction);
}

// Character::Unk_129: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
std::uint8_t Character::Unk_129()
{
	return 1;
}
