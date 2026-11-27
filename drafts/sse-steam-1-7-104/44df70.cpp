// Near miss: 1.5 alignment distance | register-schedule
// Exposure detail: (local binary analysis and labelled declarations).
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction.
// BGSPackageDataLocation: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IsRefAtLocation: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
// Cookbook: 61
// 0x44df70 BGSPackageDataLocation::IsRefAtLocation

#include "include/44df70/BGSPackageDataLocation_44df70.h"

bool BGSPackageDataLocation::IsRefAtLocation(AIWorldLocationContext& context, TESObjectREFR* ref) const
{
    if (!pointer)
        return false;
    PackageLocation* location = pointer->GetAsPackageLocation();
    if (!location)
        return false;
    return location->IsRefAtLocation(context, ref);
}
