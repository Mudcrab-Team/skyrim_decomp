// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
// 0xcd4b70 BSAudio::Shutdown
// 0xcd4b60 BSAudio::Init
// 0xcd4c20 BSAudio::GetReceiver
#include "BSAudio.h"

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
