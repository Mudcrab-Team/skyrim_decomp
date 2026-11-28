// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0xeeee30 NiStringsExtraData::dtor_deleting
// CI hash: 0xeeee30 ??_GNiStringsExtraData@@UEAAPEAXI@Z
#include "NiStringsExtraData_eeee30.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
NiStringsExtraData::NiStringsExtraData() {}

// Frees each allocated string and the pointer array before destroying NiExtraData.
NiStringsExtraData::~NiStringsExtraData()
{
    for (std::uint32_t i = 0; i < size; ++i)
    {
        NiFreeStorage(strings[i]);
    }
    NiFreeStorage(strings);
    strings = nullptr;
}
