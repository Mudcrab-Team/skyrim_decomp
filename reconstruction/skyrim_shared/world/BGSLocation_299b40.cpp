// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x299b40 BGSLocation::FindInFileFast_140242760
// Adapted bodies: none
#include "BGSLocation_299b40.h"

// Seeks directly to the saved file offset in a master TESFile and verifies the location form ID.
bool BGSLocation::FindInFileFast_140242760(TESFile* a_mod)
{
    bool found = false;
    if (a_mod && a_mod->IsMaster() && fileOffset != 0) {
        a_mod->Seek(fileOffset);
        if (a_mod->GetFormType() == 0x68 && a_mod->currentFormID == formID) {
            found = true;
        }
    }
    return found;
}
