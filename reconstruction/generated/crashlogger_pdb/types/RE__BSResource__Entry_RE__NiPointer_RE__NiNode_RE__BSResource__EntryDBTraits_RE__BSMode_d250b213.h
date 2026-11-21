// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RE::BSResource::Entry<RE::NiPointer<RE::NiNode>, RE::BSResource::EntryDBTraits<RE::BSModelDB::DBTraits, RE::BSResource::EntryDB<RE::BSModelDB::DBTraits>>::CArgs>; size 0x30
#pragma once

#include "BSTAtomicValue_unsigned_int_1b657e6f.h"
#include "BSTSmartPointer_RE__BSResource__Stream_f5000d46.h"
#include "ID.h"
#include "NiPointer_RE__NiNode_28171d5b.h"
struct RE__BSResource__Entry_RE__NiPointer_RE__NiNode_RE__BSResource__EntryDBTraits_RE__BSMode_d250b213 {
    ID name;
    BSTAtomicValue_unsigned_int_1b657e6f ctrl;
    unsigned char userData_raw[8];
    RE__BSResource__Entry_RE__NiPointer_RE__NiNode_RE__BSResource__EntryDBTraits_RE__BSMode_d250b213* next;
    BSTSmartPointer_RE__BSResource__Stream_f5000d46 stream;
    NiPointer_RE__NiNode_28171d5b data;
};
static_assert(sizeof(RE__BSResource__Entry_RE__NiPointer_RE__NiNode_RE__BSResource__EntryDBTraits_RE__BSMode_d250b213) == 48, "RE__BSResource__Entry_RE__NiPointer_RE__NiNode_RE__BSResource__EntryDBTraits_RE__BSMode_d250b213 layout differs from the PDB");
