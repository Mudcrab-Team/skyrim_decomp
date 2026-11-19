// Source exposure: mixed (pinned image listing and public names).
// Code origin: original reconstruction from the pinned image and community declarations; the earlier leaf bodies came from the project's bounded leaf template.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESPackageObjectTypeNames: GUESS(low); a table of pointers indexed by objectType, bound by position.
// TESPackage::TESPackage: GUESS(low); constructor name from the class name, body empty
// TESPackage::GetRefCount, TESPackage::GetObjectTypeName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x49e8e0 TESPackage::IsPackageOwner
// 0x49e8d0 TESPackage::GetRefCount
// 0x498940 TESPackage::ClearData
// 0x49d500 TESPackage::SaveGame
// 0x49d7a0 TESPackage::Revert
#include "TESPackage.h"

extern const char* const TESPackageObjectTypeNames[];

// Not compared: defined so that the compiler emits the vftable and the deleting destructor beside it.
TESPackage::TESPackage()
{
}

// IsPackageOwner: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint8_t TESPackage::IsPackageOwner() const
{
    return 0x1;
}

std::uint32_t TESPackage::GetRefCount() const
{
    return refCount;
}

const char* TESPackage::GetObjectTypeName() const
{
    return TESPackageObjectTypeNames[objectType];
}

void TESPackage::ClearData()
{
    delete packLoc;
    delete packTarg;
    delete idleCollection;
    delete data;
    packConditions.~TESCondition();
    TESForm::ClearData();
}

void TESPackage::SaveGame(BGSSaveFormBuffer* a_buf)
{
    if (!TESDataHandler::singleton->IsTemporaryFormID(formID)) {
        return;
    }
    a_buf->SaveDataEndian(&packFlags, 0xC, 1, 0);
    std::uint8_t flags = 0;
    if (packLoc) {
        flags |= 1;
    }
    if (packTarg) {
        flags |= 2;
    }
    if (data) {
        flags |= 4;
    }
    a_buf->SaveDataEndian(&flags, 1, 1, 0);
    if (packLoc) {
        packLoc->SaveGame(a_buf);
    }
    if (packTarg) {
        packTarg->SaveGame(a_buf);
    }
    if (data) {
        data->SaveGame(a_buf);
    }
    a_buf->SaveDataEndian(&procedureType, 4, 4, 0);
}

// TestRevertBit: GUESS(low)
static inline bool TestRevertBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1u) != 0;
}

// RVA 0x49d7a0, 77 bytes. The sign test and the bit 30 test stay independent.
void TESPackage::Revert(BGSLoadFormBuffer* a_buf)
{
    if (TESDataHandler::singleton->IsTemporaryFormID(formID)) {
        return;
    }
    const std::uint32_t flags = a_buf->oldChangeFlags;
    if (static_cast<std::int32_t>(flags) < 0) {
        packFlags &= 0xFFFF7FFFu;
    }
    if (TestRevertBit(a_buf->oldChangeFlags, 30)) {
        packFlags &= 0xFFFEFFFFu;
    }
}
