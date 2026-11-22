// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0xfa0a00 NiPSysModifierCtlr::SaveBinary
// Adapted bodies: none
// SaveBinary, NiPSysModifierBase, SaveCtlrMember: GUESS(low)
// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// NiPSysModifierCtlr: EXE_RTTI
// GetCtlrID: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
#include "NiPSysModifierCtlr.h"
// GetCtlrID: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
void* NiPSysModifierCtlr::GetCtlrID() const
{
    return member;
}

void NiPSysModifierCtlr::SaveBinary(NiStream& a_stream)
{
    NiPSysModifierBase::SaveBinary(a_stream);
    return SaveCtlrMember(a_stream, &member);
}
