// Source exposure: mixed (community headers and the pinned image listing).
// Code origin: existing unit plus original reconstruction of BSAudio constructor and Functioncd4b80.
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
// 0xcd4b70 BSAudio::Shutdown
// 0xcd4b60 BSAudio::Init
// 0xcd4c10 BSAudio::CreateMonitor
// 0xcd4c20 BSAudio::GetReceiver
// 0xcd4b80 BSAudio::Functioncd4b80
// 0xcd4bb0 BSAudio::Ctor
#include "BSAudio.h"

BSAudio::BSAudio()
    : field08(false), listener(nullptr)
{
}

void BSAudio::ApplyReverbType(const BSIReverbType*, std::uint32_t)
{
}

std::uint32_t BSAudio::CreateMonitor()
{
    return 0;
}

void BSAudio::PostGameSoundUpdates()
{
}

void BSAudio::Shutdown()
{
    field08 = false;
}

bool BSAudio::Init(REX::W32::HWND* a_wnd)
{
    field08 = true;
    return true;
}

BSAudioMonitor::Receiver BSAudio::GetReceiver(std::uint32_t a_monitor)
{
    BSAudioMonitor::Receiver result = g_bsAudioDefaultReceiver;
    return result;
}

const BSAudioVec3* BSAudio::Functioncd4b80() const
{
    if (listener) {
        return &listener->front;
    }
    return &g_bsAudioDefaultFront;
}
