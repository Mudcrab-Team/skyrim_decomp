// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
// 0x26a160 TESCombatStyle::InitItemImpl
// 0x26a890 TESCombatStyle::~TESCombatStyle
#include "TESCombatStyle.h"

// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value
inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

// The constructor is not compared: it is defined so that this unit emits the vftable and with it
// the deleting destructor.
TESCombatStyle::TESCombatStyle()
{
}

TESCombatStyle::~TESCombatStyle()
{
}

void TESCombatStyle::InitItemImpl()
{
    if (!TestBit(formFlags, 3)) {
        SetFormHelper(this, true);
    }
}
