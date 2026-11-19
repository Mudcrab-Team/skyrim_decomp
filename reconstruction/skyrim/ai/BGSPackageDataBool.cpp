// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image and community declarations.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x44d980 BGSPackageDataBool::Unk_07
// 0x44e660 BGSPackageDataBool::~BGSPackageDataBool
#include "BGSPackageDataBool.h"

// Emits the vftable and its scalar deleting destructor.
BGSPackageDataBool::BGSPackageDataBool()
{
}

// RVA 0x44d7b0, 40 bytes

// RVA 0x44d980, 54 bytes
void BGSPackageDataBool::Unk_07(BGSSaveGameBuffer* a_buf)
{
    std::uint8_t value = static_cast<std::uint8_t>((flags08 >> 1) & 1);
    a_buf->SaveDataEndian(&value, 1, 1, 0);
}

// RVA 0x44d9c0, 85 bytes

// RVA 0x44d8e0, 107 bytes
void BGSPackageDataBool::LoadPackage(TESFile* a_mod)
{
    BGSNamedPackageData_VIPackageData::LoadPackage(a_mod);
    // subrecord type "CNAM" read as a little-endian uint32
    if (a_mod->GetCurrentSubRecordType() == 0x4d414e43) {
        bool value = false;
        a_mod->ReadData(&value, 1);
        a_mod->SeekNextSubrecord();
        const std::uint64_t set = flags08 | 2;
        const std::uint64_t cleared = flags08 & ~std::uint64_t{2};
        flags08 = value ? set : cleared;
    }
}

// RVA 0x44d7e0, 87 bytes

// RVA 0x44d840, 151 bytes

// RVA 0x44e660, 81 bytes. The packed-name member releases its storage in its own destructor.
BGSPackageDataBool::~BGSPackageDataBool()
{
    flags08.bits &= ~std::uint64_t{3};
}

// Accepted leaf retained from the integrated version.
// Unk_05: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
std::uint8_t BGSPackageDataBool::Unk_05() const
{
    return 0x1;
}
