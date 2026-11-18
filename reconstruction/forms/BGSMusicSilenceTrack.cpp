// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x325bc0 BGSMusicSilenceTrack::GetDurationImpl
// 0x325b80 BGSMusicSilenceTrack::DoFinish
// 0x325b50 BGSMusicSilenceTrack::DoPause
// 0x325af0 BGSMusicSilenceTrack::DoPlay
// 0x3259f0 BGSMusicSilenceTrack::Load
#include "BGSMusicSilenceTrack.h"

// RVA 0x325bc0, 6 bytes
float BGSMusicSilenceTrack::GetDurationImpl() const
{
    return duration;
}

// RVA 0x325b80, 8 bytes
void BGSMusicSilenceTrack::DoFinish(bool a_arg1, float a_arg2)
{
    trackStatus = MUSIC_STATUS::kFinished;
}

// RVA 0x325b50, 34 bytes
void BGSMusicSilenceTrack::DoPause()
{
    pauseTime = GetTickCount();
    trackStatus = MUSIC_STATUS::kPaused;
}

// RVA 0x325af0, 90 bytes
void BGSMusicSilenceTrack::DoPlay()
{
    std::uint32_t now = GetTickCount();
    if (GetMusicStatus() == MUSIC_STATUS::kPaused) {
        playTime = (playTime - pauseTime) + now;
        trackStatus = MUSIC_STATUS::kPlaying;
        return;
    }
    playTime = now;
    trackStatus = MUSIC_STATUS::kPlaying;
}

// RVA 0x3259f0, 147 bytes
void BGSMusicSilenceTrack::Load(TESFile* a_mod)
{
    std::uint32_t type = a_mod->GetCurrentSubRecordType();
    while (type != 0) {
        if (HandleSubrecord(this, type)) {
            LoadSubrecord(this, a_mod);
        } else if (type == 0x56544c46) {
            a_mod->ReadData(&duration, 4);
            if (a_mod->unk2E9 != 0) {
                std::uint32_t& bits = *reinterpret_cast<std::uint32_t*>(&duration);
                bits = (bits >> 24) | ((bits & 0xFF0000) >> 8) | ((bits & 0xFF00) << 8) | (bits << 24);
            }
        }
        if (!a_mod->SeekNextSubrecord()) {
            break;
        }
        type = a_mod->GetCurrentSubRecordType();
    }
}
