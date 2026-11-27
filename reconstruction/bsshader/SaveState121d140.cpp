// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x121d140 SaveState121d140::Func1 (inventory/PDB guess: ImageSpaceEffectGetHit::Func1)
#include "SaveState121d140.h"

void SaveState121d140::Func1(BGSSaveFormBuffer* a_buf)
{
    unk40.SaveGame(a_buf);
    const std::uint32_t n = count;
    a_buf->SaveUInt32(n);
    for (std::uint32_t i = 0; i < n; ++i) {
        entries.data()[i].Write(a_buf);
    }
    a_buf->SaveFormData(&unkA8);
    a_buf->SaveFloat(unkB0);
    a_buf->SaveFloat(unkB4);
    a_buf->SaveUInt32(unkB8);
}
