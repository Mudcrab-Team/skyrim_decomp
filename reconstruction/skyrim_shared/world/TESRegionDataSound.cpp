// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// TESRegionDataSound: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
// 0x253310 TESRegionDataSound::GetType
#include "TESRegionDataSound.h"
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint32_t TESRegionDataSound::GetType() const
{
    return 0x7;
}

bool TESRegionDataSound::IsLoaded() const
{
    return member10 == nullptr;
}

TESRegionDataSoundObj* TESRegionDataSound::Unk_05(void* a_param)
{
    TESRegionDataSoundObj* obj = Slot4();
    obj->Slot6(a_param, 2);
    return obj;
}
