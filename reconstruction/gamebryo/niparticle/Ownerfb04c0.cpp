// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// Code origin: SaveBinary original from the pinned image listing and the declarations in NiPSysModifierCtlr.h Stamped as a twin of matched 0xfa0a00 (gamebryo/niparticle/NiPSysModifierCtlr): source copied, names replaced by placeholders.
// 0xfb04c0 Ownerfb04c0::SaveBinary
// member: GUESS(low) STANDIN
#include "Ownerfb04c0.h"

// guess: same compiled code as matched 0xfa0a00 apart from relocated fields; its role here is not established.
void Ownerfb04c0::SaveBinary(NiStream& stream)
{
    NiSingleInterpController::SaveBinary(stream);
    return stream.SaveFixedString(member);
}
