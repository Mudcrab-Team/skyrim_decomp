// Source exposure: mixed (local binary analysis and public names).
// Code origin: Stamped as a twin of matched 0x18b200 (skyrim_shared/extradata/ExtraFlags): source copied, names replaced by placeholders.
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSLoadGameBuffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function44db10, Owner44db10: GUESS(low) STANDIN
// GetType, flags: GUESS(low) STANDIN
#pragma once
#include "ExtraFlags.h"

class Owner44db10 : public BSExtraData
{
public:
    void Function44db10(BGSLoadGameBuffer* a_buf);
    virtual std::uint32_t GetType() const;

    std::uint32_t flags;  // 10
};
