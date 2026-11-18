// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BGSMenuDisplayObject: EXE_RTTI
// GetMenuDisplayObject: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
// 0x14c8c0 BGSMenuDisplayObject::GetMenuDisplayObject
// 0x1d8f80 BGSMenuDisplayObject::InitializeDataComponent
#include "BGSMenuDisplayObject.h"

// BGSMenuDisplayObject::BGSMenuDisplayObject: GUESS(low); defined so the vftable and the deleting destructor are emitted
BGSMenuDisplayObject::BGSMenuDisplayObject()
{
}

// BGSMenuDisplayObject::InitializeDataComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
void BGSMenuDisplayObject::InitializeDataComponent()
{
    member = nullptr;
}

// BGSMenuDisplayObject::ClearDataComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
void BGSMenuDisplayObject::ClearDataComponent()
{
}

// GetMenuDisplayObject: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
void* BGSMenuDisplayObject::GetMenuDisplayObject() const
{
    return member;
}
