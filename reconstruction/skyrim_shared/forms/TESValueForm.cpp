// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: TestBit
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp (TestBit, CC0-1.0)
// 0x1f34d0 Leaf1f34d0::Invoke
// 0x1f34c0 TESValueForm::InitializeDataComponent
// 0x1f36d0 TESValueForm::~TESValueForm
// 0x1f36a0 TESValueForm::LoadGame
// TESValueForm::LoadGame: GUESS(low); reads the value back when change flag bit 1 is set
#include "TESValueForm.h"

// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value
// TestBit: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0)
inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
TESValueForm::TESValueForm()
{
}

// Compared function: RVA 0x1f34d0, 3 bytes, TESValueForm::ClearDataComponent.
void TESValueForm::ClearDataComponent()
{
}

// Compared function: RVA 0x1f34c0, 8 bytes, TESValueForm::InitializeDataComponent.
void TESValueForm::InitializeDataComponent()
{
    unk08 = 0;
}

// Compared as the scalar deleting destructor; the sized delete it calls is bound by RVA in
// bind-hints.json.
TESValueForm::~TESValueForm()
{
}

void TESValueForm::LoadGame(BGSLoadFormBuffer* a_buf)
{
    if (TestBit(a_buf->changeFlags, 1)) {
        a_buf->LoadDataEndian(&unk08, 4, 4);
    }
}
