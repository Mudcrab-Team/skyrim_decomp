// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BSIMusicTrack: EXE_RTTI
// TestCanPlay: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
// 0x326f40 BSIMusicTrack::TestCanPlay
// 0x325530 Leaf325530::Invoke
#include "BSIMusicTrack.h"
// TestCanPlay: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint8_t BSIMusicTrack::TestCanPlay() const
{
    return 0x1;
}

// DoClearDucking, DoSetDuckingAttenuation, GetMusicStatus: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
void BSIMusicTrack::DoClearDucking()
{
}

void BSIMusicTrack::DoSetDuckingAttenuation(std::uint16_t a_ducking)
{
}

std::uint32_t BSIMusicTrack::GetMusicStatus() const
{
    return musicStatus;
}
