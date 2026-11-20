// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
// 0x48a730 BGSProcedureTreeProcedure::Unk_0B
// 0x48a7e0 BGSProcedureTreeProcedure::Unk_08
// 0x48a810 BGSProcedureTreeProcedure::Unk_09
// 0x48a650 BGSProcedureTreeProcedure::Unk_02
// 0x48a760 BGSProcedureTreeProcedure::Unk_0C
#include "BGSProcedureTreeProcedure.h"

// RVA 0x48a730, 40 bytes, BGSProcedureTreeProcedure::Unk_0B.
bool BGSProcedureTreeProcedure::Unk_0B()
{
    return procedure && procedure->Unk_15();
}

// RVA 0x48a7e0, 40 bytes, BGSProcedureTreeProcedure::Unk_08.
bool BGSProcedureTreeProcedure::Unk_08()
{
    return procedure && procedure->Unk_16();
}

// RVA 0x48a810, 40 bytes, BGSProcedureTreeProcedure::Unk_09.
bool BGSProcedureTreeProcedure::Unk_09()
{
    return procedure && procedure->Unk_19();
}

// RVA 0x48a650, 54 bytes, BGSProcedureTreeProcedure::Unk_02.
void BGSProcedureTreeProcedure::Unk_02(TESFile* a_mod)
{
    Unk_4a6940(&condition, a_mod);
    if (procedure) {
        procedure->Unk_05(a_mod);
    }
}

// RVA 0x48a760, 56 bytes, BGSProcedureTreeProcedure::Unk_0C.
void BGSProcedureTreeProcedure::Unk_0C(BGSProcedureBase* a_other)
{
    a_other->Unk_00(this);
    if (procedure) {
        a_other->Unk_01(procedure);
    }
}

// Accepted leaf retained from the integrated version.
// Unk_0F: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
std::uint8_t BGSProcedureTreeProcedure::Unk_0F() const
{
    return 0x1;
}
