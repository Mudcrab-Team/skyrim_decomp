// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled in the header
// 0x3c8570 TESNPC::FindInFileFast
// Adapted bodies: none
#include "TESNPC_3c8570.h"

bool TESNPC::FindInFileFast(TESFile* file)
{
    if (!file || !fileOffset) {
        return false;
    }
    if (!file->OpenTES(0, false)) {
        return false;
    }
    if (!file->Seek(fileOffset)) {
        return false;
    }
    if (file->GetFormType() != g_npcFormType) {
        return false;
    }
    if (file->currentFormID != formID) {
        return false;
    }
    return true;
}
