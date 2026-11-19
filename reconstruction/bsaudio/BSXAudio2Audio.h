// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE declarations; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Code origin: original; the listing and community declarations only
// BSXAudio2Audio, BSXAudio2Audio::~BSXAudio2Audio, BSXAudio2Audio::Init, BSXAudio2Audio::Shutdown, BSXAudio2Audio::ApplyReverbType, BSXAudio2Audio::CreateMonitor, BSXAudio2Audio::GetReceiver: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// unknown18, unknown20, unknown28, unknown30, unknown38, unknown40, unknown48, unknown50, unknown58, unknown60, unknown68, unknown70: GUESS(low); the compared destructor reads none of them
#pragma once

#include <cstdint>
#include <cstddef>
#include "bsaudio/BSAudio.h"

class BSXAudio2Audio : public BSAudio
{
public:
    virtual ~BSXAudio2Audio();  // compared: 0xcd85b0  // slot 00
    bool Init(REX::W32::HWND* a_wnd) override;  // 01
    void Shutdown() override;  // 02
    void ApplyReverbType(const BSIReverbType* a_reverbType, std::uint32_t a_tickLength) override;  // 07
    std::uint32_t CreateMonitor() override;  // 08
    BSAudioMonitor::Receiver GetReceiver(std::uint32_t a_monitor) override;  // 0A
    BSXAudio2Audio();

    std::uint64_t unknown18;  // 18
    std::uint64_t unknown20;  // 20
    std::uint64_t unknown28;  // 28
    std::uint64_t unknown30;  // 30
    std::uint64_t unknown38;  // 38
    std::uint64_t unknown40;  // 40
    std::uint64_t unknown48;  // 48
    std::uint64_t unknown50;  // 50
    std::uint64_t unknown58;  // 58
    std::uint64_t unknown60;  // 60
    std::uint64_t unknown68;  // 68
    std::uint64_t unknown70;  // 70
};
static_assert(sizeof(BSXAudio2Audio) == 0x78, "BSXAudio2Audio size");
