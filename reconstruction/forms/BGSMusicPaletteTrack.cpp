// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x325550 BGSMusicPaletteTrack::GetDurationImpl
// 0x325570 BGSMusicPaletteTrack::GetType
// 0x325000 BGSMusicPaletteTrack::DoPause
// 0x325080 BGSMusicPaletteTrack::DoFinish
// 0x324f00 BGSMusicPaletteTrack::DoPlay
// 0x324d80 BGSMusicPaletteTrack::DoUpdate
// 0x324bd0 BGSMusicPaletteTrack::InitItem
#include "BGSMusicPaletteTrack.h"

// RVA 0x325550, 6 bytes
float BGSMusicPaletteTrack::GetDurationImpl() const
{
    return m_duration;
}

// RVA 0x325570, 47 bytes: the type id is registered on first use.
TrackType BGSMusicPaletteTrack::GetType() const
{
    if (g_paletteTrackTypeId == 0) {
        RegisterTrackType(&g_paletteTrackTypeId, "BGSMusicPaletteTrack", 0);
    }
    return static_cast<TrackType>(g_paletteTrackTypeId);
}

// RVA 0x325000, 114 bytes: every selected item is paused, then the time of the pause is kept.
void BGSMusicPaletteTrack::DoPause()
{
    for (std::uint32_t i = 0; i < 3; ++i) {
        if (m_indices[i] >= 0) {
            reinterpret_cast<PaletteItem*>(m_items[i].data[static_cast<std::uint32_t>(m_indices[i])])->Pause();
        }
    }
    m_pauseStart = GetTickCount();
    m_state = 2;
}

// RVA 0x325080, 136 bytes: every selected item finishes with the flag and the float.
void BGSMusicPaletteTrack::DoFinish(bool a_arg1, float a_arg2)
{
    for (std::uint32_t i = 0; i < 3; ++i) {
        if (m_indices[i] >= 0) {
            reinterpret_cast<PaletteItem*>(m_items[i].data[static_cast<std::uint32_t>(m_indices[i])])->Finish(a_arg1, a_arg2);
        }
    }
    m_state = 3;
}
