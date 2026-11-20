// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BSIMusicTrack: EXE_RTTI
// TestCanPlay: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
#pragma once
#include <cstdint>
// TestCanPlay: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class BSIMusicTrack
{
public:
    virtual std::uint8_t TestCanPlay() const;
    // DoClearDucking, DoSetDuckingAttenuation, GetMusicStatus: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    virtual void DoClearDucking();
    virtual void DoSetDuckingAttenuation(std::uint16_t a_ducking);
    virtual std::uint32_t GetMusicStatus() const;

    // musicStatus: GUESS(low); the dword at 0x8 that GetMusicStatus returns, name invented
    std::uint32_t musicStatus;
};
