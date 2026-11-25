// Source exposure: mixed (local binary analysis, community and CrashLogger declarations).
// Code origin: original reconstruction; reduced declarations from CommonLibSSE-NG.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraAnimNoteReceiver, unk10: CRASHLOGGER_PDB(59818@2026.10.24)
// BSExtraData, next, GetType, IsNotEqual: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AnimNoteReceiverOwner: STANDIN GUESS(low); unknown dynamic receiver type
// 0x18ed70 ExtraAnimNoteReceiver::~ExtraAnimNoteReceiver
#pragma once
#include <cstdint>
#include <cstddef>

class BSExtraData
{
public:
    virtual ~BSExtraData() {}
    virtual std::uint32_t GetType() const;
    virtual bool IsNotEqual(const BSExtraData* other) const;
    BSExtraData* next;
};

class AnimNoteReceiverOwner
{
public:
    virtual ~AnimNoteReceiverOwner();
};

class ExtraAnimNoteReceiver : public BSExtraData
{
public:
    ~ExtraAnimNoteReceiver() override;
    AnimNoteReceiverOwner* unk10;
};
static_assert(sizeof(ExtraAnimNoteReceiver) == 24, "receiver layout size");
