// Source exposure: mixed (community headers and the pinned image).
// Code origin: existing unit plus original reconstruction of BSAudio constructor and Functioncd4b80. Stamped as a twin of matched 0xcd4b70 (bsaudio/BSAudio): source copied, names replaced by placeholders.
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSAudioMonitor: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) EXE_RTTI
// REX::W32::HWND: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSAudioListener, BSAudioVec3: GUESS(low)
// Ownercd6170: GUESS(low) STANDIN
// Shutdown, Init, GetReceiver, field08, unknown09, listener, Functioncd4b80: GUESS(low) STANDIN
#pragma once
#include "BSAudio.h"

class Ownercd6170
{
public:
    Ownercd6170();
    virtual void Shutdown();
    virtual void ApplyReverbType(const BSIReverbType* a_reverbType, std::uint32_t a_tickLength);
    virtual std::uint32_t CreateMonitor();
    virtual void PostGameSoundUpdates();
    virtual bool Init(REX::W32::HWND* a_wnd);
    virtual BSAudioMonitor::Receiver GetReceiver(std::uint32_t a_monitor);
    const BSAudioVec3* Functioncd4b80() const;

    bool field08;  // 08
    std::uint8_t unknown09[0x7];  // 09
    BSAudioListener* listener;  // 10
};
static_assert(sizeof(Ownercd6170) == 0x18, "Ownercd6170 size");
