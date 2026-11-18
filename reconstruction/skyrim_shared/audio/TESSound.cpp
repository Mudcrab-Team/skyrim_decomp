// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0x388860 TESSound::Clone3D
// 0x388880 TESSound::InitializeData
// 0x388620 TESSound::SetFormEditorID
// 0x3888d0 TESSound::~TESSound
#include "TESSound.h"

void SetEditorID(const char*, TESSound*);

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
TESSound::TESSound()
{
}

// TODO body: RVA 0x388860, 3 bytes, TESSound::Clone3D.
NiAVObject* TESSound::Clone3D(TESObjectREFR* a_ref)
{
    return nullptr;
}

// TODO body: RVA 0x388880, 9 bytes, TESSound::InitializeData.
void TESSound::InitializeData()
{
    unknown30 = nullptr;
}

// TODO body: RVA 0x388620, 25 bytes, TESSound::SetFormEditorID.
bool TESSound::SetFormEditorID(const char* a_str)
{
    SetEditorID(a_str, this);
    return true;
}

// TODO body: RVA 0x3888d0, 62 bytes, TESSound::~TESSound; compared as the scalar deleting
// destructor. If the target calls a separate destructor, keep only the declaration and delete this
// definition (cookbook rule 18).
TESSound::~TESSound()
{
}
