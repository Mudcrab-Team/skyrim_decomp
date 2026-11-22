// Source exposure: mixed (community headers and the pinned image).
// Code origin: existing unit plus original reconstruction of BSAudio constructor and Functioncd4b80.
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSAudio, Shutdown, Init, GetReceiver, BSAudioMonitor: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) EXE_RTTI
// REX::W32::HWND: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSAudioListener, BSAudioVec3, g_bsAudioDefaultReceiver, g_bsAudioDefaultFront, field08, unknown09, listener, Functioncd4b80: GUESS(low)
#pragma once

#include <cstdint>

namespace REX
{
    namespace W32
    {
        struct HWND;
    }
}

class BSAudioMonitor
{
public:
    class Receiver
    {
    public:
        Receiver() {}

        std::uint64_t value;
    };
};

struct BSAudioVec3
{
    float x;
    float y;
    float z;
};

struct BSAudioListener
{
    std::uint64_t unknown00;
    BSAudioVec3 front;
};

extern BSAudioMonitor::Receiver g_bsAudioDefaultReceiver;
extern BSAudioVec3 g_bsAudioDefaultFront;

class BSIReverbType;

class BSAudio
{
public:
    BSAudio();
    virtual void Shutdown();  // compared: 0xcd4b70
    virtual void ApplyReverbType(const BSIReverbType* a_reverbType, std::uint32_t a_tickLength);  // compared: 0xcd4ba0
    virtual std::uint32_t CreateMonitor();  // compared: 0xcd4c10
    virtual void PostGameSoundUpdates();  // compared: 0xcd4c30
    virtual bool Init(REX::W32::HWND* a_wnd);  // compared: 0xcd4b60
    virtual BSAudioMonitor::Receiver GetReceiver(std::uint32_t a_monitor);  // compared: 0xcd4c20
    const BSAudioVec3* Functioncd4b80() const;

    bool field08;  // 08
    std::uint8_t unknown09[0x7];  // 09
    BSAudioListener* listener;  // 10
};
static_assert(sizeof(BSAudio) == 0x18, "BSAudio size");
