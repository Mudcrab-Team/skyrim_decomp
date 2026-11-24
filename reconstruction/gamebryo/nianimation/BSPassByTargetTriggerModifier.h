// Source exposure: mixed (local binary analysis and public names).
// Code origin: Written for this reconstruction from the listing; the Unk_0A declaration follows the community header.
// Adapted bodies: none.
// BSPassByTargetTriggerModifier: EXE_RTTI
// Unk_0A: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk08: GUESS(low); padding invented to reach the measured offset
// flag90: GUESS(low); name invented for the measured offset 0x90
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xbbb3e0 BSPassByTargetTriggerModifier::Functionbbb3e0
#pragma once
#include <cstdint>
// Unk_0A: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BSPassByTargetTriggerModifier
{
public:
    virtual std::uint8_t Unk_0A() const;

    void Functionbbb3e0();

private:
    std::uint8_t unk08[0x88];
    std::uint8_t flag90;
};
