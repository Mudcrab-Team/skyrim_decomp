// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BSMultiBoundRoom: EXE_RTTI
// RegisterStreamables: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
// 0xfcdb40 BSMultiBoundRoom::RegisterStreamables
// 0xfcdb10 BSMultiBoundRoom::CreateClone
#include "BSMultiBoundRoom.h"
// RegisterStreamables: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint8_t BSMultiBoundRoom::RegisterStreamables() const
{
    return 0x1;
}

// CreateClone, LoadBinary, LinkObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declared on NiObject there and inherited, not declared on this class
void* BSMultiBoundRoom::CreateClone(void* a_cloning)
{
    return nullptr;
}

void BSMultiBoundRoom::LoadBinary(void* a_stream)
{
}

void BSMultiBoundRoom::LinkObject(void* a_stream)
{
}
