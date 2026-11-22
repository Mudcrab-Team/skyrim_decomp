// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// NiExtraDataController: EXE_RTTI
// GetCtlrID: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
#pragma once
#include <cstdint>
// GetCtlrID: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class NiExtraDataController
{
public:
    virtual void* GetCtlrID() const;
    std::uint8_t padding[0x48];
    void* member;
    // IsEqual: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24); a vtable slot in the image, declared here without virtual so GetCtlrID keeps its slot
    bool IsEqual(NiExtraDataController* a_object);
    // BaseIsEqual: GUESS(low); the base-class comparison the compared IsEqual calls first, bound by hint
    bool BaseIsEqual(NiExtraDataController* a_object);
    // extraData: GUESS(low); the extra data object at 0x58, compared through its own IsEqual
    void* extraData;
};
