// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MagicTarget, MagicTarget::~MagicTarget, postUpdateDispelList, SpellDispelData: CRASHLOGGER_PDB(59818@2026.10.24)
// next: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); member name of SpellDispelData
// unk00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct SpellDispelData
{
    uint8_t          unk00[0x18];
    SpellDispelData* next;  // 18
};

static_assert(sizeof(SpellDispelData) == 0x20, "SpellDispelData node size");

class MagicTarget
{
public:
    virtual ~MagicTarget();

    SpellDispelData* postUpdateDispelList;  // 08
};
