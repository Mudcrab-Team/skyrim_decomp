// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x49f2b0 TESCustomPackageData::GetName
// Adapted bodies: TESCustomPackageData::GetName from fo4-private@1b765c70 src/Shared/AI/PackageDataCustom.cpp:192 (see the header)
#include "TESCustomPackageData_49f2b0.h"

const char* TESCustomPackageData::GetName(const IPackageData* a_data) const
{
    std::uint8_t uid = data.GetUIDForData(a_data);
    if (uid == 0xFF || !nameMap)
        return "<unknown>";
    return nameMap->GetName(uid);
}
