// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xeaf630 NiFile::get_info
// Adapted bodies: none
#include "NiFile_eaf630.h"

void NiFile::get_info(FileInfo* a_info)
{
    a_info->unk00 = unk30;
    a_info->unk08 = unk07();
    a_info->unk0C = unk20;
    a_info->unk10 = unk24;
    a_info->unk14 = unk28;
    a_info->unk18 = unk03();
}
