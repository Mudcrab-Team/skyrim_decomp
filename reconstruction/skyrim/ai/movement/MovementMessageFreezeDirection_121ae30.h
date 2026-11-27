// Source exposure: mixed (pinned-image observations and labelled naming/declaration sources).
// Code origin: original handwritten implementation from pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MovementMessageFreezeDirection: CRASHLOGGER_PDB(59818@2026.10.24)
// BSPathingStreamRead: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
// eFreeze: SYMBOLS(fo4-pdb); offset corroborated by pinned-image access.
// Function121ae30, ReadValue, Unk00, Unk01, Unk02, Unk03: GUESS(low); placeholder method names.
#pragma once
#include <cstdint>
#include <cstddef>

class BSPathingStreamRead
{
public:
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual void ReadValue(std::uint32_t* value);
};

class MovementMessageFreezeDirection
{
public:
    void Function121ae30(BSPathingStreamRead* stream);
    std::uint8_t unknown00[0x10];
    std::uint32_t eFreeze;
};
static_assert(offsetof(MovementMessageFreezeDirection, eFreeze) == 0x10, "freeze mode offset");
