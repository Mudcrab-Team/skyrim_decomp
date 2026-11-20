// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESAmmo: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// LoadGame: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Declaration source: include/RE/T/TESAmmo.h:92 at the cited revision.
// TESValueForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// valueForm, LoadState, SaveState: GUESS(low)
#pragma once

#include <cstdint>
#include "TESForm.h"

class TESAmmo : public TESForm
{
public:
    void LoadGame(BGSLoadFormBuffer* buffer) override;

private:
    std::uint8_t padding20[0x80];
    alignas(8) std::uint8_t valueForm[0x10];
};
