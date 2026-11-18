// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x327430 BGSMusicTrackFormWrapper::InitItemImpl
// 0x327554 BGSMusicTrackFormWrapper::dtor
#include "BGSMusicTrackFormWrapper.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BGSMusicTrackFormWrapper::BGSMusicTrackFormWrapper()
{
}

// RVA 0x327430, 58 bytes: when flag bit 3 is clear and a music track is set, the track is
// notified and the form is set.
void BGSMusicTrackFormWrapper::InitItemImpl()
{
    if (!TestBit(formFlags, 3)) {
        if (musicTrack) {
            musicTrack->Slot0B(this);
            SetFormHelper(this, true);
        }
    }
}
